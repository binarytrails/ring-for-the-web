package main

import (
    "C"
    "fmt"
    "net/http"
)

var message string = ""

//export initServer
func initServer(_message *C.char){
    message = C.GoString(_message)
}

//export startServer
func startServer(){

    http.HandleFunc("/", handlerRoot)

    fmt.Println("Listening on http://127.0.0.1:8080")

    http.ListenAndServe(":8080", nil)
}

func handlerRoot(w http.ResponseWriter, request *http.Request){

    fmt.Fprint(w, message, "\n")

}

func main(){}
