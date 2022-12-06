const axios = require("axios");
const express = require("express");
const cors = require("cors");
const fs = require("fs");
var bodyParser = require("body-parser");
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

const PORT = process.env.PORT || 6999;
const app = express();
app.use(function (req, res, next) {
	// res.header("Access-Control-Allow-Origin", "*");
	// res.header("Access-Control-Allow-Headers", "X-Requested-With");
	res.setHeader("Access-Control-Allow-Origin", "*");
	res.setHeader("Access-Control-Allow-Credentials", "true");
	res.setHeader("Access-Control-Max-Age", "1810000");
	res.setHeader("Access-Control-Allow-Headers", "content-type");
	res.setHeader(
		"Access-Control-Allow-Methods",
		"PUT, POST, GET, DELETE, PATCH, OPTIONS"
	);
	next();
});
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

app.listen(PORT, () => {
	console.log("Running on :", PORT);
});

app.get("/", (req, res) => {
	res.send("Hellow World");
});

app.get("/stressTest", (req, res) => {
	console.log(req.body);
	res.send("Got the code!");
});

app.post("/stressTest", async (req, res) => {
        var data = req.body;
	fs.writeFileSync("correctCode.cpp", data.correctCode);
	fs.writeFileSync("wrongCode.cpp", data.wrongCode);
        console.log("Data Recived", data)
	fs.readFile( 
		`CodeGen/${data.quesID}.cpp`,
		"utf8",
		(err, generatorCode) => {
			fs.writeFileSync("generator.cpp", generatorCode);
		}
	);

	var exec = require("child_process").exec;

	exec("bash script.sh", function (error, stdout, stderr) {});
        
        fs.writeFileSync("finalOutput.txt", "OOPS!! Could not find any test case, try again!");
	await sleep(10000);

	await fs.readFile("finalOutput.txt", "utf8", (err, finalRes) => {
		res.send(finalRes);
        });
});
 
app.post('/generateCode', (req, res) => {
        res.send("OKAYYYY")
        let fileName = req.body.quesID;
        let code = req.body.code;
        console.log(fileName)
        fs.writeFileSync(`CodeGen/${fileName}.cpp`, code);
})

function sleep(ms) {
	return new Promise((resolve) => {
		setTimeout(resolve, ms);
	});
}
