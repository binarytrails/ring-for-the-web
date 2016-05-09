
// getting hello.cpp
const addon = require('./build/Release/hello');
console.log(addon.hello());

var ip_port_regex = require('ip-port-regex'),
    program = require('commander'),
    express = require('express'),
    app = express(),
    server = require('http').Server(app),
    io = require('socket.io')(server),
    _ = require('underscore'),
    path = require('path');

program
  .version('1.0.0')
  .usage('[options] <file ...>')
  .option('-a, --address <ip:port>', 'listen on the ip address and port', ip_port_regex.v4())
  .parse(process.argv);

if (!program.address)
{
    console.log(program.help());
    process.exit(0);
}

function basename(path)
{
   return path.split('/').reverse()[0];
}

server.listen(ip_port_regex.parts(program.address)['port'],
        ip_port_regex.parts(program.address)['ip'], function()
        {
            console.log('Listening on http://%s:%s',
                    server.address().address,
                    server.address().port
            );
        }
);

app.use(express.static(__dirname + '/public'));

app.get('/', function(req, res)
{
    res.sendFile(__dirname + '/index.html');
});

io.on('connection', function(socket)
{
    socket.emit('setContent', 'Pushed: ' + addon.hello());

    socket.on('getContent', function()
    {
        socket.emit('setContent', 'Pulled: ' + addon.hello());
    });
});

