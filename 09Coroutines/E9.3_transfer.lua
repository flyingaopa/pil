-- "goto" engine
function dispatch()
    local entry = "pil_main"
    local name = entry
    local funclist = {}
    for name, func in pairs(_ENV or {}) do
        if name:match("^pil_") and type(func) == "function" then
            funclist[name] = coroutine.create(func)
        end
    end

    while true do
        assert(funclist[name] ~= nil, name)
        local nextfunc = funclist[name]
        io.write(name .. ": ")
        status, name = coroutine.resume(nextfunc)
        --print(status, name)
        if status == false or not name then break end
    end
end

function transfer(name)
    assert(name ~= nil and name ~= "")
    print(" goto -> " .. name)
    coroutine.yield(name)
end
---------------------------------------------

--function name should be prefix with pil_

function pil_main()
    print("enter pil_main")
    transfer("pil_foo1")
    print("leave pil_main")
end

function pil_foo1()
    print("enter pil_foo1")
    transfer("pil_foo2")
    print("leave pil_foo1")
end

function pil_foo2()
    print("enter pil_foo2")
    transfer("pil_main")
    print("leave pil_foo2")
end


dispatch()
