import threading
import queue
import subprocess

TIMEOUT_S = 1

def enqueue_output(out: subprocess.Popen["str"], queue):
    queue.put(out.readline())

def read_line_with_timeout(process: subprocess.Popen["str"]):
    # Create a queue and a thread to read the subprocess's output
    q = queue.Queue()
    t = threading.Thread(target=enqueue_output, args=(process.stdout, q))
    t.daemon = True  # Thread dies with the program
    t.start()

    try:
        ret = q.get(timeout=TIMEOUT_S).strip()
        if process.poll():
            raise RuntimeError("Vaš program se ugasio prijevremeno. Exit code: " + str(process.returncode))
        return ret
    except queue.Empty:
        raise TimeoutError("Isteklo je vrijeme za odgovor (" + str(TIMEOUT_S) + "s) " +
            "Možda ste zaboravili staviti novu liniju na kraju ispisa (\\n)? Simulator i judge " +
            "čitaju vaš ispis liniju po liniju."
        )
        