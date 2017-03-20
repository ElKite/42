var fileSystem = require('fs');
var first_function = function () {
	/*
		I'm a comment
	*/
	fileSystem.writeFile("./Grace_kid.js", "var fileSystem = require('fs');\nvar first_function = " + first_function.toString() + ";\nvar main = " + main.toString() + ";\nmain();", (err) => {});
};
var main = function () {
	first_function();
};
main();