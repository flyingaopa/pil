local foo
do
    local _ENV = _ENV
    function foo () print(X) end
    end
    X = 13
--    _ENV = nil
    foo()
    X = 0
    ---
    --
    --
    --
local print = print
function foo (_ENV, a)
print(a + b)
end
foo({b = 14}, 12)
foo({b = 10}, 1)
