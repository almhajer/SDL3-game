cmake_minimum_required(VERSION 3.20)
project(BK.app VERSION "0.0.1")

# تحديد مستوى C++ المستخدم
set(CMAKE_CXX_STANDARD 17)

# تحديد المسارات
set(FILE_PROJECT "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(BUILD_DIR "${CMAKE_BINARY_DIR}/BKgame")
set(APP_NAME "BK.app")
set(APP_DIR "${BUILD_DIR}/${APP_NAME}/Contents")
set(APP_BIN_DIR "${APP_DIR}/MacOS")
set(APP_RES_DIR "${APP_DIR}/Resources")

# إعداد مسار تثبيت SDL3
set(SDL3_INCLUDE_DIR "/usr/local/SDL3/include/")  # مسار ملفات رأس SDL3
set(SDL3_LIBRARY_DIR "/usr/local/Cellar/sdl3/3.2.10/lib")  # مسار مكتبة SDL3

# إعداد مسار تثبيت SDL3_image
set(SDL3_IMAGE_INCLUDE_DIR "/usr/local/Cellar/sdl3_image/3.2.4/include/")  # مسار ملفات رأس SDL3_image
set(SDL3_IMAGE_LIBRARY_DIR "/usr/local/lib")  # مسار مكتبة SDL3_image

# إعداد مسار تثبيت SDL3_ttf
set(SDL3_TTF_INCLUDE_DIR "/usr/local/Cellar/sdl3_ttf/3.2.2/include/")  # مسار ملفات رأس SDL3_ttf
set(SDL3_TTF_LIBRARY_DIR "/usr/local/Cellar/sdl3_ttf/3.2.2/lib/")  # مسار مكتبة SDL3_ttf

#SDL3_MIXER
set(SDL3_MIXER_INCLUDE_DIR "/usr/local/include/")  # مسار ملفات رأس SDL3_MIXER
set(SDL3_MIXER_LIBRARY_DIR "/usr/local/lib/")  # مسار ملفات رأس SDL3_MIXER

# إعداد المسارات للإخراج
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# إنشاء المجلدات داخل .app
file(MAKE_DIRECTORY ${APP_BIN_DIR})
file(MAKE_DIRECTORY ${APP_RES_DIR})

# نسخ الملفات مثل Info.plist و icon.icns
configure_file("${CMAKE_SOURCE_DIR}/Info.plist" "${APP_DIR}/Info.plist" COPYONLY)
configure_file("${CMAKE_SOURCE_DIR}/icon.icns" "${APP_RES_DIR}/icon.icns" COPYONLY)

# تضمين ملفات الرأس
include_directories(${FILE_PROJECT}
        ${SDL3_INCLUDE_DIR}
        ${SDL3_IMAGE_INCLUDE_DIR}
        ${SDL3_TTF_INCLUDE_DIR}
        ${SDL3_MIXER_INCLUDE_DIR}
)


# تحديد مسارات المكتبات
link_directories(${SDL3_LIBRARY_DIR}
        ${SDL3_IMAGE_LIBRARY_DIR}
        ${SDL3_TTF_LIBRARY_DIR}
        ${SDL3_MIXER_LIBRARY_DIR}
)

# إضافة الملفات المصدرية
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${FILE_PROJECT}/*.hpp" "${FILE_PROJECT}/*.h")

# إضافة الملف التنفيذي
add_executable(BK ${SOURCES})

# تعريف المتغير MY_VARIABLE الذي يحتوي على مسار مجلد الصور
target_compile_definitions(BK PRIVATE FOLDER_IMAGES="${CMAKE_CURRENT_SOURCE_DIR}/images/")

# إعداد ملف التجميع المسبق
target_precompile_headers(BK PRIVATE ${FILE_PROJECT}/precompiled.hpp)

# ربط مكتبة SDL3
target_link_libraries(BK PRIVATE
        ${SDL3_LIBRARY_DIR}/libSDL3.0.dylib
        # ربط مكتبة SDL3_image
        ${SDL3_IMAGE_LIBRARY_DIR}/libSDL3_image.0.dylib
        # ربط مكتبة SDL3_ttf
        ${SDL3_TTF_LIBRARY_DIR}/libSDL3_ttf.0.2.2.dylib
        #SDL3_MIXER
        ${SDL3_MIXER_LIBRARY_DIR}/libSDL3_mixer.dylib
)

# نسخ الملف التنفيذي إلى مجلد MacOS بعد البناء
add_custom_command(TARGET BK POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:BK> ${APP_BIN_DIR}/BK
        COMMENT "نسخ الملف التنفيذي إلى MacOS"
)
