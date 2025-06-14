rm att/simulator.zip
cd simulator
rm -rf dist
rm -rf build
pyinstaller simulator.spec
mv dist/simulator/_internal/primjeri.txt dist/simulator
cd dist
cd simulator
zip -r9 simulator.zip .
mv simulator.zip ../../../att
cd ..
cd ..
cd ..