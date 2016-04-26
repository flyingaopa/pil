local so= require "csocket"
local host = "www.w3.org"
local file = "/TR/REC-html32.html"
local threads = {}

function download(host,file)
    local sk = so.socket(so.AF_INET, so.SOCK_STREAM, 0)
--  sk:setdebug(true)

    sk:connect(host, 80)
    sk:setblocking(0)

    local count = 0
    sk:send("GET " .. file  .. " HTTP/1.0\r\n\r\n")
	while true do
	    local msg, err = sk:recv(1024)
	    if msg then
	        if #msg == 0 then break end
            count = count + #msg
	    else
            if err == 11 then
                coroutine.yield(err)
            end
	    end
	end
    sk:close()
    print(file, count)
end

function get(host,file)
    local co = coroutine.create(function() download(host, file) end)
    table.insert(threads, co)
end


function dispatch()
    while true do
        for k, v in ipairs(threads) do
            if v then
                local status, ret = coroutine.resume(v)
                if not ret then table.remove(threads, k) end
            end
        end
        if #threads == 0 then break end
    end
end


get(host, "/TR/html401/html40.txt")
get(host, "/TR/2002/REC-xhtml1-20020801/xhtml1.pdf")
get(host, file)
get(host, "/TR/2000/REC-DOM-Level-2-Core-20001113/DOM2-Core.txt")

print(os.time())
dispatch()
print(os.time())
