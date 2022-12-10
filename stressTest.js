const fs = require("fs");

async function stressTest(req, res) {
	try {
		var data = req.body;
		fs.writeFileSync("stressZone/correctCode.cpp", data.correctCode);
		fs.writeFileSync("stressZone/wrongCode.cpp", data.wrongCode);
		fs.readFile(
			`CodeGen/${data.quesID}.cpp`,
			"utf8",
			(err, generatorCode) => {
				fs.writeFileSync("stressZone/generator.cpp", generatorCode);
			}
		);

		var exec = require("child_process").exec;

		exec("bash script.sh", function (error, stdout, stderr) { });

		fs.writeFileSync(
			"stressZone/finalOutput.txt",
			"OOPS!! Could not find any test case, try again!"
		);
		await sleep(10000);

		await fs.readFile(
			"stressZone/finalOutput.txt",
			"utf8",
			(err, finalRes) => {
				res.send(finalRes);
			}
		);
	} catch (error) {
		// handle the error here
		res.send("An error occurred: " + error.message);
	}
}

function sleep(ms) {
	return new Promise((resolve) => {
		setTimeout(resolve, ms);
	});
}

// Export the stressTest function
module.exports = {
	stressTest,
};
