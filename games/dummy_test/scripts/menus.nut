::CurrentMenu <- null;
::MainMenu <- null;
::SaveMenu <- null;
::LoadMenu <- null;
::OptionsMenu <- null;

//::Quit <-function(){}

::NoMenu <- {
    get_clicked_button = function(){
        return {func = function(){if(MouseLeftPressed()) PrintFunction(GetMousePosX().tostring() + ", " + GetMousePosX().tostring());}};
    }
}

CurrentMenu = NoMenu;

::MainMenu <- {

    position = {x = 600, y = 400}
    buttons = [
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "New Savefile"
            func = function(){CurrentMenu = SaveMenu;}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Load Savefile"
            func = function(){CurrentMenu = LoadMenu;}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Options"
            func = function(){CurrentMenu = OptionsMenu;}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Quit"
            func = function(){Quit();}
        }
    ]
    set_positions = function(_x, _y){}
    offset_positions = function(_x, _y){}
    get_clicked_button = function(){
        foreach (button in buttons) {
            if(/*RectVsPoint(Rect(button.position, button.size), GetMousePos())*/ true){
                return button;
            }
        }
        return {func = function(){}};
    }
    draw = function(){}
}

::UpdateMenus <- function(){
    CurrentMenu.get_clicked_button().func();
}

UpdateMenus();