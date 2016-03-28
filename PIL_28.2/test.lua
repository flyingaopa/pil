libs = require "split"
print("####")
ret = libs.split2("h\0i:ho\0:t\0her\0e:final",":")
for k,v in ipairs(ret) do print(v, v:len()) end

print("####")
ret = libs.split2("h\0i:ho\0:t\0her\0e:final","\0")
for k,v in ipairs(ret) do print(v, v:len()) end

