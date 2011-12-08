require 'mkmf'
extension_name = 'nnls'
dir_config(extension_name)

# $CFLAGS << ' -g'

create_makefile(extension_name)
