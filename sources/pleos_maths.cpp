//******************
//
// pleos_maths.cpp
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
// This file contains the source code of "pleos_maths.h".
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

// Include PLEOS Libs
#include "../headers/pleos_maths.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Maths_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        // Functions
        if(object_name == "maths_functions_definitions_body") {a_functions_definitions_page = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_definitions_page;}
        if(object_name == "maths_functions_forms_body") {a_functions_forms_page = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_forms_page;}
        if(object_name == "maths_functions_redaction_body") {a_functions_redaction_page = *parent->new_object<scls::GUI_Object>(object_name);return a_functions_redaction_page;}
        if(object_name == "maths_functions_redaction") {a_functions_redaction = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_redaction;}
        if(object_name == "maths_functions_redaction_analyse") {a_functions_redaction_analyse = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_redaction_analyse;}
        if(object_name == "maths_functions_redaction_elements"){a_functions_redaction_elements = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_functions_redaction_elements;}
        if(object_name == "maths_functions_redaction_elements_chosen"){a_functions_redaction_elements_chosen = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_functions_redaction_elements_chosen;}
        if(object_name == "maths_functions_redaction_expression"){a_functions_redaction_expression = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_functions_redaction_expression;}
        if(object_name == "maths_functions_redaction_graphic"){a_functions_redaction_graphic = *parent->new_object<Graphic>(object_name);return a_functions_redaction_graphic;}

        // Geometry
        if(object_name == "maths_geometry_definitions_body") {a_geometry_definitions_body = *parent->new_object<scls::GUI_Text>(object_name);return a_geometry_definitions_body;}
        if(object_name == "maths_geometry_complex_numbers_body") {a_geometry_complex_numbers_page = *parent->new_object<scls::GUI_Text>(object_name);return a_geometry_complex_numbers_page;}
        if(object_name == "maths_geometry_redaction"){a_geometry_redaction = *parent->new_object<scls::GUI_Text>(object_name);return a_geometry_redaction;}
        if(object_name == "maths_geometry_redaction_analyse"){a_geometry_redaction_analyse = *parent->new_object<scls::GUI_Text>(object_name);return a_geometry_redaction_analyse;}
        if(object_name == "maths_geometry_redaction_body"){a_geometry_redaction_page = *parent->new_object<scls::GUI_Object>(object_name);return a_geometry_redaction_page;}
        if(object_name == "maths_geometry_redaction_elements_choice"){a_geometry_redaction_elements = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_geometry_redaction_elements;}
        if(object_name == "maths_geometry_redaction_elements_chosen"){a_geometry_redaction_elements_chosen = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_geometry_redaction_elements_chosen;}
        if(object_name == "maths_geometry_redaction_elements_created"){a_geometry_redaction_elements_created = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_geometry_redaction_elements_created;}
        if(object_name == "maths_geometry_redaction_elements_creation"){a_geometry_redaction_elements_creation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_geometry_redaction_elements_creation;}
        if(object_name == "maths_geometry_redaction_vector_name"){a_geometry_redaction_vector_name = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_geometry_redaction_vector_name;}
        if(object_name == "maths_geometry_redaction_vector_x"){a_geometry_redaction_vector_x = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_geometry_redaction_vector_x;}
        if(object_name == "maths_geometry_redaction_vector_y"){a_geometry_redaction_vector_y = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_geometry_redaction_vector_y;}

        // Pages
        if(object_name == "maths_functions_page") {a_functions_page = *parent->new_object<scls::GUI_Object>(object_name);return a_functions_page;}
        if(object_name == "maths_geometry_page"){a_geometry_page = *parent->new_object<scls::GUI_Object>(object_name);return a_geometry_page;}

        // Navigation
        if(object_name == "maths_navigation") {a_navigation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_navigation;}

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }

    // Adds an element to analyse
    void Maths_Page::add_element(std::string current_choice) {
        // Creation name
        std::string final_choice = current_choice;
        if(current_choice == "vector"){
            final_choice += std::string("-") + std::to_string(geometry_redaction_elements_chosen()->count_object_similar("vector", "-"));
        }

        // Get the good current choice
        std::shared_ptr<scls::GUI_Object>* object = geometry_redaction_elements_chosen()->add_object(final_choice);

        // Do the good configuration
        if(object != 0) {
            int needed_height = 30;
            std::string needed_title = "";
            // Creation settings
            if(current_choice == "vector_norm"){
                needed_height = 60;
                needed_title = std::string("Norme");
            }

            final_choice = object->get()->name();
            object->get()->set_border_width_in_pixel(1);
            object->get()->set_height_in_pixel(needed_height);
            geometry_redaction_elements_chosen()->place_objects();

            // Create the title
            std::shared_ptr<scls::GUI_Text> title = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title");
            title.get()->attach_top_in_parent();
            title.get()->set_height_in_pixel(30);
            title.get()->set_width_in_scale(1);
            title.get()->set_x_in_object_scale(scls::Fraction(1, 2));
            title.get()->set_text(needed_title);

            // Finalise the creation
            if(current_choice == "vector_norm"){
                // Create the title of the name of the needed vector
                std::shared_ptr<scls::GUI_Text> name_title = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title_name");
                name_title.get()->attach_bottom_of_object_in_parent(title);
                name_title.get()->set_height_in_pixel(30);
                name_title.get()->set_width_in_scale(scls::Fraction(1, 2));
                name_title.get()->set_x_in_object_scale(scls::Fraction(1, 4));
                name_title.get()->set_text(std::string("Vecteur :"));

                // Create the name of the needed vector
                std::shared_ptr<scls::GUI_Text_Input> name_input = *object->get()->new_object<scls::GUI_Text_Input>(final_choice + "_name");
                name_input.get()->attach_bottom_of_object_in_parent(title);
                name_input.get()->set_border_width_in_pixel(1);
                name_input.get()->set_height_in_pixel(30);
                name_input.get()->set_width_in_scale(scls::Fraction(1, 5));
                name_input.get()->set_x_in_object_scale(scls::Fraction(3, 4));
            }
        }
    }

    // Adds an element to create
    void Maths_Page::add_element_created(std::string current_choice) {
        // Creation name
        std::string final_choice = current_choice;
        std::string needed_title = "";
        if(current_choice == "vector"){
            final_choice += std::string("-") + std::to_string(geometry_redaction_elements_created()->count_object_similar("vector", "-"));
            needed_title = std::string("Vecteur");

            // Create the needed vector
            geometry_vectors_created().push_back(std::make_shared<pleos::Vector>("", 1, 1));
            geometry_select_vector(geometry_vectors_created()[geometry_vectors_created().size() - 1]);
        }

        // Get the good current choice
        std::shared_ptr<scls::GUI_Text>* object = geometry_redaction_elements_created()->add_object(final_choice, needed_title);
        if(object != 0){currently_selected_vector()->set_connected_object(*object);}
    }

    // Selects a geometry vector
    void Maths_Page::geometry_select_vector(std::shared_ptr<pleos::Vector> needed_vector) {
        check_geometry_hiding();
        currently_selected_vector_shared_ptr() = needed_vector;

        // Set the needed text
        geometry_redaction_vector_name()->set_text(needed_vector.get()->name());
        geometry_redaction_vector_x()->set_text(needed_vector.get()->x()->to_std_string());
        geometry_redaction_vector_y()->set_text(needed_vector.get()->y()->to_std_string());
    }

    // Check the events of functions
    void Maths_Page::check_functions() {
        // Analyse a function
        if(functions_redaction_analyse()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            // Get datas and asserts
            std::string function_name = std::string("f");
            std::string needed_function = functions_redaction_expression()->text();
            if(needed_function == "") {return;}
            scls::Formula needed_formula = scls::string_to_formula(needed_function);

            // Check the graphic part
            functions_redaction_graphic()->reset();
            functions_redaction_graphic()->add_function(needed_formula);

            // Do the redaction
            Function_Studied fs; fs.function_formula = needed_formula; fs.function_name = function_name; fs.function_unknown = std::string("x");
            std::string redaction = std::string("Nous avons la fonction ") + function_name + std::string(" tel que :</br></br>");
            redaction += std::string("<math><mi>") + function_name + std::string("(x") + std::string(")</mi><mo>=</mo>") + needed_formula.to_mathml() + std::string("</math></br></br>");

            // Add the needed arguments
            std::vector<scls::GUI_Scroller_Choice::GUI_Scroller_Single_Choice>& objects = functions_redaction_elements_chosen()->objects();
            for(int i = 0;i<static_cast<int>(objects.size());i++) {
                std::string complete_name = objects[i].name(); std::vector<std::string> cutted = scls::cut_string(complete_name, std::string("-"));
                std::string type = cutted[0];

                // Analyse the argument
                if(type == "definition_set") { function_definition_set(fs, redaction); }
                else if(type == "image") {
                    scls::Formula needed_value = scls::string_to_formula(reinterpret_cast<scls::GUI_Text_Input*>(objects[i].object()->child_by_name(objects[i].object()->name() + "_input_x"))->text());
                    function_image(fs, needed_value, redaction);
                } redaction += std::string("</br></br>");
            }

            functions_redaction()->set_text(redaction);
        }

        // Add a chosen element
        if(functions_redaction_elements()->selection_modified()) {
            std::string current_choice = functions_redaction_elements()->currently_selected_objects_during_this_frame()[0].name();
            functions_redaction_elements()->unselect_object(functions_redaction_elements()->currently_selected_objects()[0]);

            // Creation name
            std::string final_choice = current_choice;
            if(current_choice == "image"){
                final_choice += std::string("-") + std::to_string(functions_redaction_elements_chosen()->count_object_similar("image", "-"));
            }

            // Get the good current choice
            std::shared_ptr<scls::GUI_Object>* object = functions_redaction_elements_chosen()->add_object(final_choice);

            // Do the good configuration
            if(object != 0) {
                int needed_height = 30;
                std::string needed_title = "";
                // Creation settings
                if(current_choice == "definition_set"){
                    needed_title = std::string("Ensemble de définition");
                }
                else if(current_choice == "image"){
                    needed_height = 60;
                    needed_title = std::string("Image");
                }

                final_choice = object->get()->name();
                object->get()->set_border_width_in_pixel(1);
                object->get()->set_height_in_pixel(needed_height);
                functions_redaction_elements_chosen()->place_objects();

                // Create the title
                std::shared_ptr<scls::GUI_Text> title = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title");
                title.get()->attach_top_in_parent();
                title.get()->set_height_in_pixel(30);
                title.get()->set_width_in_scale(1);
                title.get()->set_x_in_object_scale(scls::Fraction(1, 2));
                title.get()->set_text(needed_title);

                // Finalise the creation
                if(current_choice == "image"){
                    // Create the title
                    std::shared_ptr<scls::GUI_Text> title_x = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title_x");
                    title_x.get()->attach_bottom_of_object_in_parent(title);
                    title_x.get()->attach_left_in_parent();
                    title_x.get()->set_height_in_pixel(30);
                    title_x.get()->set_text(std::string("Pour x = "));
                    title_x.get()->set_width_in_scale(scls::Fraction(1, 2));

                    // Create the input
                    std::shared_ptr<scls::GUI_Text_Input> input_x = *object->get()->new_object<scls::GUI_Text_Input>(final_choice + "_input_x");
                    input_x.get()->attach_bottom_of_object_in_parent(title);
                    input_x.get()->attach_right_in_parent();
                    input_x.get()->set_border_width_in_pixel(1);
                    input_x.get()->set_height_in_pixel(30);
                    input_x.get()->set_width_in_scale(scls::Fraction(1, 2));
                }
            }
        }
    }

    // Check the events of geometry
    void Maths_Page::check_geometry() {
        // Analyse the geometry
        if(geometry_redaction_analyse()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            // Do the redaction
            check_geometry_hiding();
            std::string redaction = std::string();
            if(static_cast<int>(geometry_vectors_created().size()) > 1){redaction += std::string("Nous allons définir ") + std::to_string(geometry_vectors_created().size()) + std::string(" vecteurs. ");}
            for(int i = 0;i<static_cast<int>(geometry_vectors_created().size());i++) {
                redaction += geometry_vectors_created()[i].get()->introduction();
                if(i < static_cast<int>(geometry_vectors_created().size()) - 1){redaction += std::string(" ");}
            } redaction += std::string("</br></br>");

            // Add the needed arguments
            std::vector<scls::GUI_Scroller_Choice::GUI_Scroller_Single_Choice>& objects = geometry_redaction_elements_chosen()->objects();
            for(int i = 0;i<static_cast<int>(objects.size());i++) {
                redaction += std::string("</br></br>");
                std::string complete_name = objects[i].name(); std::vector<std::string> cutted = scls::cut_string(complete_name, std::string("-"));
                std::string type = cutted[0];

                // Analyse the argument
            }//*/

            geometry_redaction()->set_text(redaction);
        }

        // Add a chosen element
        if(geometry_redaction_elements()->selection_modified()) {
            std::string current_choice = geometry_redaction_elements()->currently_selected_objects_during_this_frame()[0].name();
            geometry_redaction_elements()->unselect_object(geometry_redaction_elements()->currently_selected_objects()[0]);
            add_element(current_choice);
        }

        // Add a created element
        if(geometry_redaction_elements_creation()->selection_modified()) {
            std::string current_choice = geometry_redaction_elements_creation()->currently_selected_objects_during_this_frame()[0].name();
            geometry_redaction_elements_creation()->unselect_object(geometry_redaction_elements_creation()->currently_selected_objects()[0]);
            add_element_created(current_choice);
        }

        // Select a created element
        for(int i = 0;i<static_cast<int>(a_current_state.a_geometry_vectors_created.size());i++) {
            if(a_current_state.a_geometry_vectors_created[i].get()->connected_object()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
                geometry_select_vector(a_current_state.a_geometry_vectors_created[i]);
            }
        }
    }

    // Checks the events of hiding geometry page
    void Maths_Page::check_geometry_hiding() {
        if(currently_selected_vector() != 0) {
            // Get the X and Y
            scls::Formula needed_x = scls::string_to_formula(geometry_redaction_vector_x()->text());
            scls::Formula needed_y = scls::string_to_formula(geometry_redaction_vector_y()->text());

            // Set the needed values
            currently_selected_vector()->set_name(geometry_redaction_vector_name()->text());
            currently_selected_vector()->set_x(needed_x);
            currently_selected_vector()->set_y(needed_y);
        }
    }

    // Checks the events of hiding all pages
    void Maths_Page::check_hiding() {
        // Check geometry hiding
        if(current_page() == PLEOS_MATHS_GEOMETRY_REDACTION_PAGE){check_geometry_hiding();}
    }

     // Check the events of navigation
    void Maths_Page::check_navigation() {
        // Check the selected page
        if(a_navigation.get()->selection_modified()){
            std::string page = a_navigation.get()->currently_selected_objects_during_this_frame()[0].name();

            // Functions pages
            if(page == "functions_definitions"){display_functions_definitions_page();}
            else if(page == "functions_forms"){display_functions_forms_page();}
            else if(page == "functions_graphic"){display_functions_redaction_graphic_page();}
            else if(page == "functions_redaction"){display_functions_redaction_page();}
            else if(page == "geometry_complex_numbers"){display_geometry_complex_numbers_page();}
            else if(page == "geometry_redaction"){display_geometry_redaction_page();}
        }
    }

    // Update the events
    void Maths_Page::update_event() {
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();

        // Check the good page
        if(current_page() == PLEOS_MATHS_FUNCTIONS_REDACTION_PAGE){check_functions();}
        // Check the good page
        if(current_page() == PLEOS_MATHS_GEOMETRY_REDACTION_PAGE){check_geometry();}
    }
}
