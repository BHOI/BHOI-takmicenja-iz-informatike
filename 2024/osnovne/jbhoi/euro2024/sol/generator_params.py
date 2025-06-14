def b(val: bool):
   return "true" if val else "false"

params = []
finish_names = {
   -2:  "Nasumično",
   -1:  "Svi različiti bodovi",
   0:   "Samo način 1",
   1:   "Samo način 2",
   2:   "Samo način 3",
   3:   "Samo način 4",
   4:   "Razigravanje"
}
column_widths = [20, 16, 18, 16, 15, 17]
print("|      Vrsta završetka | Isti broj mečeva | Nasumičan rezultat | Pobjeđuju domaći | Pobjeđuju gosti | Uvijek neriješeno |")
print("|----------------------|------------------|--------------------|------------------|-----------------|-------------------|")
for finish in [0, 1, 2, 3, 4, -1, -2]:
  for balance in [True, False]:
    print("|", finish_names[finish].rjust(column_widths[0]), "| ", end = "")
    print(("DA" if balance else "NE").ljust(column_widths[1]), "| ", end = "")
    column_idx = 1
    for win_home in [True, False]:
      for win_away in [True, False]:
        column_idx += 1
        not_random = not win_home or not win_away
        always_even = not win_home and not win_away
        should_ignore = False
        if finish != -2:
          if always_even and finish == 0:
            should_ignore = True
          if balance:
            if not_random and finish in [-1, 3, 4]:
              should_ignore = True
        if not should_ignore:
          params.append((b(balance), b(win_home), b(win_away), finish))
          print("**2**".ljust(column_widths[column_idx]), end = "")
        else:
          print(" ".ljust(column_widths[column_idx]), end = "")
        print(" | ", end = "")
    print()
print()
for param in params:
  print("    Parametri(%s, %s, %s, %d)," % param)
print("    // total:", len(params))
print()
print("subtask_count", len(params), " ".join(map(
  lambda p: "7" if p[3] == -2 and p[2] == "true" and p[1] == "true" else "2", params
)))