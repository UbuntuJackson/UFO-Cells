::menu_state <- null;
::MainMenu <- null;
::SaveMenu <- null;
::LoadMenu <- null;
::OptionsMenu <- null;

::Quit <-function(){}

::MainMenu <- {

    position = {x = 600, y = 400}
    buttons = [
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "New Savefile"
            func = function(){menu_state = SaveMenu;}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Load Savefile"
            func = function(){menu_state = LoadMenu;}
        },
        {
            position = {x = null, y = null}
            size = {x = null, y = null}
            name = "Options"
            func = function(){menu_state = OptionsMenu;}
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
            if(RectVsPoint(Rect(button.position, button.size), GetMousePos())){
                return button;
            }
        }
        return null;
    }
    draw = function(){/*Enter drawing-call here*/}
}