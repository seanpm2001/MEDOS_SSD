for f in "ada.ads" "a-unccon.ads" "a-uncdea.ads" "gnat.ads" "g-souinf.ads" \
"interfac.ads" "s-atacco.adb" "s-atacco.ads" "s-maccod.ads" "s-stoele.adb" \
"s-stoele.ads"
do
cp /usr/lib/gcc/x86_64-linux-gnu/4.6/adainclude/$f rts/src/
ln -s `pwd`/rts/src/$f `pwd`/rts/boards/i386/adainclude/$f
done