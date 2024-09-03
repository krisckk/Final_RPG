cmake_minimum_required(VERSION 3.27)
project(2024_I2P2_FinalProject_MiniRPGgame)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Resource)

file(COPY Resource/audios DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Resource/fonts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Resource/images DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Resource DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY allegro_monolith-5.2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(Engine)

add_executable(2024_I2P2_TowerDefense_with_answer
        Engine/IScene.cpp
        Engine/Allegro5Exception.cpp
        Engine/Allegro5Exception.hpp
        Engine/AudioHelper.cpp
        Engine/AudioHelper.hpp
        Engine/Collider.cpp
        Engine/Collider.hpp
        Engine/GameEngine.cpp
        Engine/GameEngine.hpp
        Engine/Group.cpp
        Engine/Group.hpp
        Engine/IControl.cpp
        Engine/IControl.hpp
        Engine/IObject.cpp
        Engine/IObject.hpp
        Engine/IScene.hpp
        Engine/LOG.cpp
        Engine/LOG.hpp
        Engine/Point.cpp
        Engine/Point.hpp
        Engine/Resources.cpp
        Engine/Resources.hpp
        Engine/Sprite.cpp
        Engine/Sprite.hpp
        UI/Component/Image.cpp
        UI/Component/Image.hpp
        UI/Component/ImageButton.cpp
        UI/Component/ImageButton.hpp
        UI/Component/Label.cpp
        UI/Component/Label.hpp
        UI/Component/Slider.cpp
        UI/Component/Slider.hpp
        Scene/StartScene.hpp
        Scene/StartScene.cpp
        Scene/Achievement.hpp
        Scene/Achievement.cpp
        Scene/MenuSettings.hpp
        Scene/MenuSettings.cpp
        Scene/LoseScene.hpp
        Scene/LoseScene.cpp
        Scene/WinScene.cpp
        Scene/WinScene.hpp
        Scene/Map/Map.hpp
        Scene/Map/Map.cpp
        Scene/UndergroundShelter/B4/LabScene.hpp
        Scene/UndergroundShelter/B4/LabScene.cpp
        Scene/UndergroundShelter/B4/LibraryScene.hpp
        Scene/UndergroundShelter/B4/LibraryScene.cpp
        Scene/UndergroundShelter/B4/Computer.cpp
        Scene/UndergroundShelter/B4/Computer.hpp
        Scene/UndergroundShelter/B4/StorageRoom.hpp
        Scene/UndergroundShelter/B4/StorageRoom.cpp
        Scene/UndergroundShelter/B4/ElevatorB4.cpp
        Scene/UndergroundShelter/B4/ElevatorB4.hpp
        Scene/UndergroundShelter/B3/ElevatorB3.hpp
        Scene/UndergroundShelter/B3/ElevatorB3.cpp
        Scene/UndergroundShelter/B3/RestRoom.cpp
        Scene/UndergroundShelter/B3/RestRoom.hpp
        Scene/UndergroundShelter/B3/GYMscene.hpp
        Scene/UndergroundShelter/B3/GYMscene.cpp
        Scene/UndergroundShelter/B3/DiningRoom.hpp
        Scene/UndergroundShelter/B3/DiningRoom.cpp
        Scene/UndergroundShelter/B3/DataRoom.hpp
        Scene/UndergroundShelter/B3/DataRoom.cpp
        Scene/UndergroundShelter/B2/ElevatorB2.cpp
        Scene/UndergroundShelter/B2/ElevatorB2.hpp
        Scene/UndergroundShelter/B2/BiologicalLaboratory.hpp
        Scene/UndergroundShelter/B2/BiologicalLaboratory.cpp
        Scene/UndergroundShelter/B1/ElevatorB1.hpp
        Scene/UndergroundShelter/B1/ElevatorB1.cpp
        Scene/UndergroundShelter/B1/HardwareRoom.hpp
        Scene/UndergroundShelter/B1/HardwareRoom.cpp
        Scene/UndergroundShelter/B1/Office.cpp
        Scene/UndergroundShelter/B1/Office.hpp
        Scene/UndergroundShelter/B1/ElevatorToFloor.hpp
        Scene/UndergroundShelter/B1/ElevatorToFloor.cpp
        Scene/UndergroundShelter/Floor/ElevatorFloor.hpp
        Scene/UndergroundShelter/Floor/ElevatorFloor.cpp
        Scene/UndergroundShelter/Floor/Factory.cpp
        Scene/UndergroundShelter/Floor/Factory.hpp
        Scene/UndergroundShelter/Floor/CraftingTable.cpp
        Scene/UndergroundShelter/Floor/CraftingTable.hpp
        Scene/Ground/Home.cpp
        Scene/Ground/Home.hpp
        Scene/Ground/House.cpp
        Scene/Ground/House.hpp
        Scene/Ground/Road.cpp
        Scene/Ground/Road.hpp
        Maincharacter/Animation.hpp
        Maincharacter/Animation.cpp
        Maincharacter/MainCharacter.hpp
        Maincharacter/MainCharacter.cpp
        Maincharacter/Backpack.cpp
        Maincharacter/Backpack.hpp
        Maincharacter/PauseScene.hpp
        Maincharacter/PauseScene.cpp
        Monster/Monster.cpp
        Monster/Monster.hpp
        Stats/Shared.cpp
        Stats/Shared.hpp
        main.cpp
)

IF (WIN32)
    target_include_directories(2024_I2P2_TowerDefense_with_answer PUBLIC C:/allegro/include)
    target_link_directories(2024_I2P2_TowerDefense_with_answer PUBLIC C:/allegro/lib)
    target_compile_options(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_CFLAGS_OTHER})
    target_link_libraries(2024_I2P2_TowerDefense_with_answer liballegro_monolith)
ELSE()
    find_package(PkgConfig)
    pkg_check_modules(ALLEGRO5 REQUIRED allegro-5 allegro_main-5 allegro_font-5 allegro_dialog-5 allegro_primitives-5 allegro_image-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5)
    target_include_directories(2024_I2P2_TowerDefense_with_answer PUBLIC lib)
    target_include_directories(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_INCLUDE_DIRS})
    target_compile_options(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_CFLAGS_OTHER})
    target_link_libraries(2024_I2P2_TowerDefense_with_answer ${ALLEGRO5_LIBRARIES})
    target_link_directories(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_LIBRARY_DIRS})
ENDIF()