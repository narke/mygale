#include <Elementary.h>

void
event_handler(void *data, Evas_Object *obj, const char *emission, const char *source)
{
	if (!strcmp(emission, "back,clicked"))
	{
		printf("back\n");
	}
	else if (!strcmp(emission, "forward,clicked"))
	{
		printf("forward\n");
	}
	else if (!strcmp(emission, "reload,clicked"))
	{
		printf("reload\n");
	}
	else if (!strcmp(emission, "stop,clicked"))
	{
		printf("stop\n");
	}
	else if (!strcmp(emission, "go-jump,clicked"))
	{
		Edje_External_Param param = {"text", EDJE_EXTERNAL_PARAM_TYPE_STRING, 0, 0, NULL};

		if (edje_object_part_external_param_get(obj, "url", &param))
		{
			printf("URL: %s\n", param.s);
		}
	}
}

EAPI_MAIN int
elm_main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	Evas_Object *win, *background, *box, *separator, *top, *browser, *progressbar;
	Efl_Canvas_Object *edje;

	elm_policy_set(ELM_POLICY_QUIT, ELM_POLICY_QUIT_LAST_WINDOW_CLOSED);

	win = elm_win_util_standard_add("Main", "Mygale");
	elm_win_autodel_set(win, EINA_TRUE);

	background = elm_bg_add(win);
	elm_win_resize_object_add(win, background);
	evas_object_size_hint_weight_set(background, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(background);

	box = elm_box_add(win);
	elm_win_resize_object_add(win, box);
	evas_object_size_hint_weight_set(box, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(box);

	top = elm_layout_add(win);
	elm_layout_file_set(top, "top.edj", "top_group");
	evas_object_size_hint_weight_set(top, EVAS_HINT_EXPAND, 0);
	evas_object_size_hint_align_set(top, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_box_pack_end(box, top);
	evas_object_show(top);

	separator = elm_separator_add(win);
	elm_separator_horizontal_set(separator, 1);
	elm_box_pack_end(box, separator);
	evas_object_show(separator);

	// top.edj Callbacks
	edje = elm_layout_edje_get(top);
	edje_object_signal_callback_add(edje, "back,clicked", "*", event_handler, (void *)browser);
	edje_object_signal_callback_add(edje, "forward,clicked", "*", event_handler, (void *)browser);
	edje_object_signal_callback_add(edje, "reload,clicked", "*", event_handler, (void *)browser);
	edje_object_signal_callback_add(edje, "stop,clicked", "*", event_handler, (void *)browser);
	edje_object_signal_callback_add(edje, "go-jump,clicked", "*", event_handler, (void *)browser);

	evas_object_resize(win, 800, 600);
	evas_object_show(win);

	elm_run();

	return 0;
}
ELM_MAIN()
