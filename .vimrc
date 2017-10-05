map <F7> :!pushd $PROJECT_ROOT/build; emmake make config=emscriptendebug -j8; popd;<CR>
map <F8> :!pushd $PROJECT_ROOT/build; emmake make config=emscriptenrelease -j8; popd;<CR>

