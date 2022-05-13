set (COMPONENTS_DIR "../components/")
set (LIB "ota_lib")
set (METHOD "native_ota")
set (LOG "log")
set (PLATFORM "esp32")

idf_component_register(SRCS "main.c" "file_server.c" "mount.c" "ota_server.c"
                            ${COMPONENTS_DIR}/${LIB}/${METHOD}/${PLATFORM}/ota.c
                            ${COMPONENTS_DIR}/${LIB}/${LOG}/${PLATFORM}/ota_log.c
                    INCLUDE_DIRS "."
                            ${COMPONENTS_DIR}/${LIB}/include
                            ${COMPONENTS_DIR}/${LIB}/${METHOD}/${PLATFORM}/
                        EMBED_FILES "favicon.ico" "upload_script.html")
