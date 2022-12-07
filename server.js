const express = require("express");
const cors = require("cors");
const fs = require("fs");
var bodyParser = require("body-parser");
const { stressTest } = require("./stressTest"); // Import the stressTest function

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
	res.send("Got the code!");
});

app.post("/stressTest", stressTest); // Use the imported stressTest function as the route handler

app.post("/generateCode", (req, res) => {
	res.send("OKAYYYY");
	let fileName = req.body.quesID;
	let code = req.body.code;
	console.log(fileName);
	fs.writeFileSync(`CodeGen/${fileName}.cpp`, code);
});
