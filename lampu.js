// npm install express socket.io --s

//inisiasi express
const express = require("express")
const app = express()

// buka port
app.listen(process.env.port||3000,function(){
    console.log("Server is running at port flexible or"+3000)
})

app.get("/",function(req,res){
    res.send({
        suhu:80
    })
})

app.get("/mikro1/:lampu1/:lampu2/:code",function(req,res){
    res.send({
        lampu1:req.params.lampu1,
        lampu2:req.params.lampu2,
        code:req.params.code
    })
})

// localhost:3000/mikro1/1/1/200
// app.get("/getSuhu/:suhu",function(req,res){
//     res.send({
//         suhu:req.params.suhu
//     })
// })