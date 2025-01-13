//******************
//
// pleos_maths.h
//
//******************
// Presentation :
//
// PLEOS, by Aster System, is a project which aims education.
// By using the power of SCLS and other Aster System's tools, we created  this.
// We want to make education easier for everyone (teachers, as students and pupils).
// The software is made in french, because the main goal is France educational system.
// For more information, see : https://aster-system.github.io/aster-system/projects/pleos.html.
//
// The "Maths" part aims mathematics lessons.
// Its goal is to provide a big amount of well structured informations, with animations and solving system.
//
// This file contains the page of the Maths plugin.
//
//******************
//
// License (GPL V3.0) :
//
// Copyright (C) 2024 by Aster System, Inc. <https://aster-system.github.io/aster-system/>
// This file is part of PLEOS.
// PLEOS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PLEOS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with PLEOS. If not, see <https://www.gnu.org/licenses/>.
//

#ifndef PLEOS_MATHS
#define PLEOS_MATHS

// Include PLEOS Libs
#include "../../pleos_libs/pleos_mathematics.h"

// Possible pages
#define PLEOS_MATHS_HOME_PAGE 0
// Functions pages
#define PLEOS_MATHS_FUNCTIONS_PAGE 100
#define PLEOS_MATHS_FUNCTIONS_REDACTION_PAGE 101

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Maths_Page : public scls::GUI_Page {
        // Class representating the "Maths" page for PLEOS
    public:

        // Maths_Page constructor
        Maths_Page(scls::_Window_Advanced_Struct* window_struct, std::string name):scls::GUI_Page(window_struct, name){};
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        //******************
        //
        // Functions handling
        //
        //******************

        //******************
        //
        // Check the events
        //
        //******************

        // Function called after the XML loading
        virtual void after_xml_loading(){scls::GUI_Page::after_xml_loading();hide_sub_pages(true);a_functions_redaction_elements_chosen.get()->unselected_objects_style().cursor = GLFW_ARROW_CURSOR;};
        // Check the events of functions
        void check_functions();
        // Check the events of navigation
        void check_navigation();
        // Update the events
        virtual void update_event();

        //******************
        //
        // Handle the pages
        //
        //******************

        // Displays the functions page
        void display_functions_page(){hide_all();functions_page()->set_visible(true);};
        void display_functions_definitions_page(){display_functions_page();functions_definitions_page()->set_visible(true);};
        void display_functions_forms_page(){display_functions_page();functions_forms_page()->set_visible(true);};
        void display_functions_redaction_page(){set_current_page(PLEOS_MATHS_FUNCTIONS_REDACTION_PAGE);display_functions_page();functions_redaction_page()->set_visible(true);};
        // Displays the geometry page
        void display_geometry_page(){hide_all();geometry_page()->set_visible(true);};
        void display_geometry_complex_numbers_page(){display_geometry_page();geometry_complex_numbers_page()->set_visible(true);};

        // Hides all the pages
        void hide_all(){hide_sub_pages(true);};

        // Returns / resets the current page
        inline unsigned short current_page() const {return a_current_state.current_page;};
        inline void set_current_page(unsigned short new_page) {a_current_state.current_page = new_page;};

        //******************
        //
        // GUI handling
        //
        //******************

        // Returns pages
        inline scls::GUI_Text* functions_definitions_page() const {return a_functions_definitions_page.get();};
        inline scls::GUI_Object* functions_forms_page() const {return a_functions_forms_page.get();};
        inline scls::GUI_Object* functions_page() const {return a_functions_page.get();};
        inline scls::GUI_Object* functions_redaction_page() const {return a_functions_redaction_page.get();};
        inline scls::GUI_Object* geometry_page() const {return a_geometry_page.get();};
        inline scls::GUI_Scroller_Choice* navigation() const {return a_navigation.get();};

        //  Returns functions
        inline scls::GUI_Text* functions_redaction() const {return a_functions_redaction.get();};
        inline scls::GUI_Object* functions_redaction_analyse() const {return a_functions_redaction_analyse.get();};
        inline scls::GUI_Scroller_Choice* functions_redaction_elements() const {return a_functions_redaction_elements.get();};
        inline scls::GUI_Scroller_Choice* functions_redaction_elements_chosen() const {return a_functions_redaction_elements_chosen.get();};
        inline scls::GUI_Text_Input* functions_redaction_expression() const {return a_functions_redaction_expression.get();};

        // Returns geometry
        inline scls::GUI_Object* geometry_complex_numbers_page() const {return a_geometry_complex_numbers_page.get();};

    private:

        // Current state of the page
        struct {
            // Current page
            unsigned short current_page = PLEOS_MATHS_HOME_PAGE;
        } a_current_state;

        // Global navigation
        std::shared_ptr<scls::GUI_Scroller_Choice> a_navigation;

        // Pages
        std::shared_ptr<scls::GUI_Object> a_functions_page;
        std::shared_ptr<scls::GUI_Object> a_geometry_page;

        // Functions page
        std::shared_ptr<scls::GUI_Text> a_functions_definitions_page;
        std::shared_ptr<scls::GUI_Object> a_functions_forms_page;
        std::shared_ptr<scls::GUI_Text> a_functions_redaction;
        std::shared_ptr<scls::GUI_Text> a_functions_redaction_analyse;
        std::shared_ptr<scls::GUI_Object> a_functions_redaction_page;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_functions_redaction_elements;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_functions_redaction_elements_chosen;
        std::shared_ptr<scls::GUI_Text_Input> a_functions_redaction_expression;

        // Geometry page
        std::shared_ptr<scls::GUI_Object> a_geometry_complex_numbers_page;
        std::shared_ptr<scls::GUI_Text> a_geometry_definitions_body;
    };

    class __Temp_Pleos_Window : public scls::Window {
        // Temporary used window by PLEOS
    public :
        // __Temp_Pleos_Window constructor
        __Temp_Pleos_Window(unsigned int w, unsigned int h, std::string path) : scls::Window(w, h, path) { set_window_title(std::string("PLEOS - Maths")); }

        // Create an object in the window
        std::shared_ptr<scls::Object> __create_loaded_object_from_type(std::string object_name, std::string object_type) {if(object_name == "maths") {std::shared_ptr<Maths_Page> hub = *new_page_2d<Maths_Page>(object_name);return hub;} return scls::Window::__create_loaded_object_from_type(object_name, object_type);}
    };
}

#endif // PLEOS_MATHS
