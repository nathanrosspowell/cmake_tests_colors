@echo off
if not exist build md build
pushd build
ctest
popd
