producer = function()
    while true do
        local x = io.read()
        send(x)
    end
end


consumer = coroutine.create(
function(p)
    local msg = p
    repeat
        io.write(msg, "\n")
        msg = receive()
    until not true
end)


function receive()
    local value = coroutine.yield()
    return value
end

function send(x)
    coroutine.resume(consumer, x)
end


producer()
