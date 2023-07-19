
::Menus <- {}

Menus["NoMenu"] <- {
    get_clicked_button = function(){
        return {func = function(){if(MouseLeftPressed()) PrintFunction(GetMousePosX().tostring() + ", " + GetMousePosX().tostring());}};
    }
}

Menus["MainMenu"] <- {

    position = {x = 600, y = 200}
    size = {x = 400, y = 400}
    buttons = [
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "New Savefile"
            func = function(){
                SetMenu("NewGameMenu");
            }
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Load Savefile"
            func = function(){
                SetMenu("LoadMenu");
            }
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Options"
            func = function(){
                SetMenu("OptionsMenu");
            }
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Quit"
            func = function(){
                Quit();
            }
        }
    ]
    set_positions = function(){
        foreach(index, button in buttons){
            button.size.x = 400
            button.size.y = 100;
        }
        foreach(index, button in buttons){
            button.position.x = position.x
            button.position.y = position.y + index * button.size.y + index * 5;
        }
    }
    offset_positions = function(_x, _y){}
    get_clicked_button = function(){
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                return button;
            }
        }
        return {func = function(){}};
    }
    draw = function(){
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 50, 200, 200, 255);
            }
            else{
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 20, 170, 180, 255);
            }
            DrawStringDecal(button.position.x + 20, button.position.y + 20, button.name, 255, 255, 255, 255, 3.0, 3.0);
        }
    }
}

Menus["LoadMenu"] <- {

    position = {x = 600, y = 200}
    size = {x = 400, y = 400}
    buttons = [
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "File 1"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "File 2"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "File 3"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Back"
            func = function(){
                SetMenu("MainMenu");
            }
        }
    ]
    set_positions = function(){
        foreach(index, button in buttons){
            button.size.x = 400
            button.size.y = 100;
        }
        foreach(index, button in buttons){
            button.position.x = position.x
            button.position.y = position.y + index * button.size.y + index * 5;
        }
    }
    offset_positions = function(_x, _y){}
    get_clicked_button = function(){
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                return button;
            }
        }
        return {func = function(){}};
    }
    draw = function(){
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 50, 195, 140, 255);
            }
            else{
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 20, 180, 110, 255);
            }
            DrawStringDecal(button.position.x + 20, button.position.y + 20, button.name, 255, 255, 255, 255, 3.0, 3.0);
        }
    }
}

Menus["NewGameMenu"] <- {

    position = {x = 600, y = 200}
    size = {x = 400, y = 400}
    buttons = [
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "File 1"
            func = function(){
                SetState("load", "../games/dummy_test/res/map/zen/zen.json");
            }
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "File 2"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "File 3"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Back"
            func = function(){
                SetMenu("MainMenu");
            }
        }
    ]
    set_positions = function(){
        foreach(index, button in buttons){
            button.size.x = 400
            button.size.y = 100;
        }
        foreach(index, button in buttons){
            button.position.x = position.x
            button.position.y = position.y + index * button.size.y + index * 5;
        }
    }
    offset_positions = function(_x, _y){}
    get_clicked_button = function(){
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                return button;
            }
        }
        return {func = function(){}};
    }
    draw = function(){
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 50, 195, 140, 255);
            }
            else{
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 20, 180, 110, 255);
            }
            DrawStringDecal(button.position.x + 20, button.position.y + 20, button.name, 255, 255, 255, 255, 3.0, 3.0);
        }
    }
}

Menus["OptionsMenu"] <- {

    position = {x = 600, y = 200}
    size = {x = 400, y = 400}
    buttons = [
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Audio"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Input"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Language"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Advanced"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Back"
            func = function(){
                SetMenu("MainMenu");
            }
        }
    ]
    set_positions = function(){
        foreach(index, button in buttons){
            button.size.x = 400
            button.size.y = 100;
        }
        foreach(index, button in buttons){
            button.position.x = position.x
            button.position.y = position.y + index * button.size.y + index * 5;
        }
    }
    offset_positions = function(_x, _y){}
    get_clicked_button = function(){
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                return button;
            }
        }
        return {func = function(){}};
    }
    draw = function(){
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 230, 170, 130, 255);
            }
            else{
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 200, 150, 100, 255);
            }
            DrawStringDecal(button.position.x + 20, button.position.y + 20, button.name, 255, 255, 255, 255, 3.0, 3.0);
        }
    }
}

Menus["PauseOptions"] <- {

    position = {x = 600, y = 200}
    size = {x = 400, y = 400}
    buttons = [
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Audio"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Input"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Language"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Advanced"
            func = function(){}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Back"
            func = function(){
                SetMenu("PauseMenu");
            }
        }
    ]
    set_positions = function(){
        foreach(index, button in buttons){
            button.size.x = 400
            button.size.y = 100;
        }
        foreach(index, button in buttons){
            button.position.x = position.x
            button.position.y = position.y + index * button.size.y + index * 5;
        }
    }
    offset_positions = function(_x, _y){}
    get_clicked_button = function(){
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                return button;
            }
        }
        return {func = function(){}};
    }
    draw = function(){
        DrawMap();
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 230, 170, 130, 225);
            }
            else{
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 200, 150, 100, 225);
            }
            DrawStringDecal(button.position.x + 20, button.position.y + 20, button.name, 255, 255, 255, 255, 3.0, 3.0);
        }
    }
}

Menus["PauseMenu"] <- {

    position = {x = 600, y = 200}
    size = {x = 400, y = 400}
    buttons = [
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Resume"
            func = function(){
                SetState("play", "...")
            }
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Options"
            func = function(){
                SetMenu("PauseOptions");
            }
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Save & Quit"
            func = function(){
                SetMenu("MainMenu")
            }
        }
    ]
    set_positions = function(){
        foreach(index, button in buttons){
            button.size.x = 400;
            button.size.y = 100;
        }
        foreach(index, button in buttons){
            button.position.x = position.x
            button.position.y = position.y + index * button.size.y + index * 5;
        }
    }
    offset_positions = function(_x, _y){}
    get_clicked_button = function(){
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                return button;
            }
        }
        return {func = function(){}};
    }
    draw = function(){
        DrawMap();
        foreach (button in buttons) {
            if(RectangleVsPoint(button.position.x, button.position.y, button.size.x, button.size.y, GetMousePosX(), GetMousePosY())){
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 50, 200, 200, 225);
            }
            else{
                FillRectangleDecal(button.position.x, button.position.y, button.size.x, button.size.y, 20, 170, 180, 225);
            }
            DrawStringDecal(button.position.x + 20, button.position.y + 20, button.name, 255, 255, 255, 255, 3.0, 3.0);
        }
    }
}

Menus.MainMenu.set_positions();
Menus.OptionsMenu.set_positions();
Menus.LoadMenu.set_positions();
Menus.NewGameMenu.set_positions();
Menus.PauseMenu.set_positions();
Menus.PauseOptions.set_positions();

//CurrentMenu = Menus[GetStateData()];

::SetMenu <- function(_menu){
    SetState("menu", _menu);
}

::UpdateMenus <- function(){
    Menus[GetStateData()].draw();
    if(MouseLeftPressed()) Menus[GetStateData()].get_clicked_button().func();
    //Menus[GetStateData()].draw();
}