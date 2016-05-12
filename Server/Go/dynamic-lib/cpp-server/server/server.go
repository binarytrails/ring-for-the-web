package server

import (
    "C"
    "fmt"
    "net/http"
)

//export startServer
func startServer(){

    http.HandleFunc("/", handlerRoot)

    fmt.Println("Listening on http://127.0.0.1:8080")

    http.ListenAndServe(":8080", nil)
}

func handlerRoot(w http.ResponseWriter, request *http.Request){

    fmt.Fprint(w, "Home page\n")

}

func main(){}
