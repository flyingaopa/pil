dir = require "dir"
for fname in dir.open("/home/cloud") do
    print(fname)
end

