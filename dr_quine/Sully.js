var fileSystem = require("fs");
var exec = require("child_process").exec;
var path = require("path");
var file = path.basename(__filename);
var it = 5;

!function main() {

	if (file == "Sully.js") {
		var name = "Sully_" + it + ".js";
	} else if (it >= 0) {
		it -= 1;
	}

	if (it >= 0) {
		fileSystem.writeFile("./Sully_" + it + ".js", `var fileSystem = require("fs");\nvar exec = require("child_process").exec;\nvar path = require("path");\nvar file = path.basename(__filename);\nvar it = ` + it + `;\n\n` + `!${main.toString()}();`, (err) => {});
		exec("node Sully_" + it + ".js", (err) => {});
	}
}();