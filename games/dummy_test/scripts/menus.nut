::CurrentMenu <- null;
::MainMenu <- null;
::NewGameMenu <- null;
::LoadMenu <- null;
::OptionsMenu <- null;

::NoMenu <- {
    get_clicked_button = function(){
        return {func = function(){if(MouseLeftPressed()) PrintFunction(GetMousePosX().tostring() + ", " + GetMousePosX().tostring());}};
    }
}

::MainMenu <- {

    position = {x = 600, y = 200}
    size = {x = 400, y = 400}
    buttons = [
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "New Savefile"
            func = function(){
                CurrentMenu = LoadMenu;
            }
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Load Savefile"
            func = function(){
                CurrentMenu = LoadMenu;
            }
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Options"
            func = function(){
                CurrentMenu = OptionsMenu;
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

::LoadMenu <- {

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
                CurrentMenu = MainMenu;
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

::NewGameMenu <- {

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
                CurrentMenu = MainMenu;
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

::OptionsMenu <- {

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
                CurrentMenu = MainMenu;
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

MainMenu.set_positions();
OptionsMenu.set_positions();
LoadMenu.set_positions();
LoadMenu.set_positions();

CurrentMenu = MainMenu;

::UpdateMenus <- function(){
    if(MouseLeftPressed()) CurrentMenu.get_clicked_button().func();
    CurrentMenu.draw();
}