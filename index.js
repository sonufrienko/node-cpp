const {
  helloWorld,
  addNumbers,
  getStringLength
} = require("./build/Release/addon");

/**
 * Execute function from C++ addon
 */

console.log(`helloWorld:\t\t\t\t${helloWorld()}`);

console.log(`addNumbers(3, 9):\t\t\t${addNumbers(3, 9)}`);

console.log(`getStringLength('OpenSource'):\t\t${getStringLength("OpenSource")}`);
