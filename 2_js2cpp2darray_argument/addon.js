var addon = require('bindings')('addon.node');

var obj = new addon.MyObject();
console.log(obj.jsToCpp2DArray([["aa","bb","cc","dd"],["aaa","bbb","ccc","ddd"]]));

/* ----node addon.js output------
*
 constructor call over
 array length=2
 i=0 j=0 element =aa
 i=0 j=1 element =bb
 i=0 j=2 element =cc
 i=0 j=3 element =dd
 i=1 j=0 element =aaa
 i=1 j=1 element =bbb
 i=1 j=2 element =ccc
 i=1 j=3 element =ddd
 { msg:
 [ [ 'aa', 'bb', 'cc', 'dd' ], [ 'aaa', 'bbb', 'ccc', 'ddd' ] ] }
* */