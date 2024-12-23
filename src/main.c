#include <errors.h>
#include <exec.h>
#include <config.h>

int main(int argc, char** argv) {
	int err = run(get_config());
	if (err) {
		PANIC(get_exec_error_message(err));
	}

	return 0;
}



