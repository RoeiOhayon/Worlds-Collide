#include <spdlog/spdlog.h>

#include "UI/Root.h"
#include "UI/Components.h"

int main()
{
	std::vector<const char*> items = { "Wormhole", "Crytal Cave", "Sea"};

	App app = App(UIProps({ .name = "MyApp" }),
		std::make_shared<Row>(
			std::make_shared<Text>(UIProps({ .col = 0, .colWidth = 0.25f }), "Scenes"),
			std::make_shared<Text>(UIProps({ .col = 1, .colWidth = 0.75f }), "Active Scene")
		),
		std::make_shared<Row>(
			std::make_shared<Menu<const char*>>(UIProps({ .col = 0, .colWidth = 0.5f }), items, items[0])
		)
	);

	spdlog::info("Starting app...");
	Root root = Root(app);
	root.render();

	return 0;
}