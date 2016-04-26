local so= require "csocket"
local host = "www.w3.org"
local file = "/TR/REC-html32.html"

local sk = so.socket(so.AF_INET, so.SOCK_STREAM, 0)
sk:setdebug(true)

sk:connect(host, 80)
sk:setblocking(0)

sk:send("GET " .. file  .. " HTTP/1.0\r\n\r\n")
while true do
    local msg, err = sk:recv(1024)
    if msg then
        if #msg == 0 then break end
        --io.write(msg)
    else
--        print(err)
    end
end

sk:close()
