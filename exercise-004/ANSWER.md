# Aufgabe 4 – Prüfung des Segments (.rodata)

Verwendete Symbole
 image        = 3145728 Bytes
 `image_width`  = 1024 px
 `image_height` = 1024 px

---

Prüfung des Segments mit:

Verwendeter Befehl:

```bash
reader -S build/bin/exercise-004

[17] .rodata           PROGBITS         0000000000052000  00052000
       0000000000001d53  0000000000000000   A       0     0     16

objdump -t build/bin/exercise-004

000000000005389b  w    O .rodata        0000000000000015              _ZTSN3CLI12InvalidErrorE


--------------------------------------------------------------------------------------------------------

Verwendete Symbole
 image        = 24576 Bytes
 `image_width`  = 128 px
 `image_height` = 64 px

readelf -s build/bin/exercise-004 | grep image_uc
50: 00000000000530a8     4 OBJECT  LOCAL  DEFAULT   17 _ZL14image_uc_width
51: 00000000000530ac     4 OBJECT  LOCAL  DEFAULT   17 _ZL15image_uc_height

╰$ objdump -C -t build/bin/exercise-004 | grep image_uc
00000000000530a8 l     O .rodata        0000000000000004              image_uc_width
00000000000530ac l     O .rodata        0000000000000004              image_uc_height 
