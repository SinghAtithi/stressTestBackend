import express from "express";

var exec = require("child_process").exec;

exec("bash script.sh", function (error, stdout, stderr) {});
