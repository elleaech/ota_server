set (COMPONENTS_DIR "../components/")
set (LIB "ota_lib")
set (PLATFORM "esp32")

idf_component_register(SRCS "main.c" "file_server.c" "mount.c"
                            ${COMPONENTS_DIR}/${LIB}/${PLATFORM}/ota.c
                            ${COMPONENTS_DIR}/${LIB}/${PLATFORM}/ota_log.c
                    INCLUDE_DIRS "."
                            ${COMPONENTS_DIR}/${LIB}/include
                            ${COMPONENTS_DIR}/${LIB}/${PLATFORM}/
                    EMBED_FILES "favicon.ico" "upload_script.html")
