var iosocket = io.connect();

function content(text)
{
    document.getElementById('content').innerHTML = text;
}
//hello('test');

iosocket.on('setContent', function(text)
{
    content(text);
});

// ajax
$('#getContent').on('click', function()
{
    iosocket.emit('getContent');
});

