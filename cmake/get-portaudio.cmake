set(DEPENDENCY_EXTRACT_DIR ${DEPENDENCY_DIR}/extract)
set(DEPENDENCY_INSTALL_DIR ${DEPENDENCY_DIR}/install)

ExternalProject_Add(project_portaudio
	UPDATE_COMMAND 		""
    GIT_REPOSITORY      https://git.assembla.com/portaudio.git
	GIT_TAG				799a6834a5
    PREFIX              ${DEPENDENCY_EXTRACT_DIR}
	INSTALL_DIR 		${DEPENDENCY_INSTALL_DIR}
	CMAKE_ARGS
		-DCMAKE_INSTALL_PREFIX=${DEPENDENCY_INSTALL_DIR}
		#-DPA_USE_DS=OFF
		#-DPA_USE_WASAPI=OFF
		#-DPA_USE_WDMKS=OFF
		#-DPA_USE_WDMKS_DEVICE_INFO=OFF
)