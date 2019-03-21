var addon = require('bindings')('addon.node');

var obj = new addon.MyObject();
console.log(obj.jsToCpp2DArray([["aa","bb","cc","dd"],["aaa","bbb","ccc","ddd"]]));

/* ----node addon.js output------
*

* */