include(C:/Onyx/ServerTCP_SCPI_QtNetwork/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/ServerTcpTest-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Onyx/ServerTCP_SCPI_QtNetwork/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/ServerTcpTest.exe
    GENERATE_QT_CONF
)
