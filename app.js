const express = require("express")
const app = express()

let statusLampu = 0;
let statusLampu2 = 0;

app.listen(3000,function(){
    console.log("Server is running")
})

app.get("/:lampu/:lampu2",function(req,res){
    statusLampu = req.params.lampu
    statusLampu2 = req.params.lampu2
    res.redirect("/")
})

app.get("/",function(req,res){
    res.send({
        lampu:statusLampu,
        lampu2:statusLampu2
    })
})