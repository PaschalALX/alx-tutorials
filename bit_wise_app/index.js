let permission = 0
let permsToDislay = "none"
let permsSpan = document.getElementById("permsSpan")
let permsForm = document.forms.permsForm

permsSpan.innerText = permsToDislay
permsSpan.classList.add("none")

let togglePermission = (perm)=>{
    permission = permission ^ 1 << perm
}

let displayUserPerms = ()=>{
    let perms = []

    if (permission & 1 << 2)
        perms.push("read")

    if (permission & 1 << 1)
        perms.push("write")
    
    if (permission & 1 << 0)
        perms.push("execute")

    if (perms.length)
    {
        permsToDislay = perms.join(', ')
        if (perms.length == 3)
        {
            permsSpan.classList.add("all")
            permsSpan.classList.remove("none")
        } 
        else
        {
            permsSpan.classList.remove("all")
            permsSpan.classList.remove("none")
        }
    }
    else
    {
        permsSpan.classList.add("none")
        permsSpan.classList.remove("all")
        permsToDislay = "none"
    }

    permsSpan.innerText = permsToDislay
}

permsForm.addEventListener("click",(evt)=>{
    if (evt.target == this.read)
    {
        togglePermission(2)
        displayUserPerms()
    }
    else if(evt.target == this.write)
    {
        togglePermission(1)
        displayUserPerms()
    }
    else if(evt.target == this.execute)
    {
        togglePermission(0)
        displayUserPerms()
    }
})