Example usge for your own init files.

1. Create a directory `myProject`
2. Save the `bb_init.h` file in the (same) directory `myProject`
3. Create an Arduino file `mySketch.ino` in the directory `myProject`
4. Run the sketch and view the output

```
#include "bb_init.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(BUTTON1_PIN);
}
```

See http://arduino.cc/en/Guide/Libraries
