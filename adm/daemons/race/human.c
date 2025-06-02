// human.c
#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
([      "action":	       "$N��ȭ����$n��$l",
	"damage_type":  "����",
]),
([      "action":	       "$N��$n��$lһץ",
	"damage_type":  "ץ��",
]),
([      "action":	       "$N��$n��$l�ݺݵ�����һ��",
	"damage_type":  "����",
]),
([      "action":	       "$N����ȭͷ��$n��$l��ȥ",
	"damage_type":  "����",
]),
([      "action":	       "$N��׼$n��$l�����ӳ�һȭ",
	"damage_type":  "����",
]),
});

void create()
{
	seteuid(getuid());
}

void setup_human(object ob)
{
	mapping my;
	int s;
	int x, y;
	int xflv,level, level_old;
	string xinfa;

	if(xinfa = ob->query_skill_mapped("xinfa"))
		xflv = ob->query_skill(xinfa,1);
	else
		xflv = 0;

	my = ob->query_entire_dbase();

	ob->set_default_action(__FILE__, "query_action");
	if (! stringp(my["unit"])) my["unit"] = "λ";
	if (! stringp(my["gender"])) my["gender"] = "����";
	if (undefinedp(my["can_speak"])) my["can_speak"] = 1;
	if (! stringp(my["attitude"])) my["attitude"] = "peaceful";
	if (! pointerp(my["limbs"])) my["limbs"] = ({
		"ͷ��", "����", "�ؿ�", "����", "���", "�Ҽ�", "���",
		"�ұ�", "����", "����", "����", "С��", "����", "����",
		"���", "�ҽ�"
	});

	if (undefinedp(my["age"])) my["age"] = 14;
	if (undefinedp(my["str"])) my["str"] = 10 + random(21);
	if (undefinedp(my["con"])) my["con"] = 10 + random(21);
	if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
	if (undefinedp(my["int"])) my["int"] = 10 + random(21);
	if (undefinedp(my["per"])) my["per"] = 10 + random(21);

	if (userp(ob) || undefinedp(my["max_jing"]))
	{
		s = ob->query_int();
		my["max_jing"] = 200;
		if (undefinedp(my["born"]))
			; else
		if (my["age"] < 14)
			my["max_jing"] = 150 + my["age"] * s * 2 / 3;
		else
		if (my["age"] < 24)
			my["max_jing"] += (my["age"] - 14) * s * 2 / 3;
		else
			my["max_jing"] += (24 - 14) * s * 2 / 3;

		if ((int)my["max_jingli"] > 0)
			my["max_jing"] += (int)my["max_jingli"] / 3;

		if (my["breakup"])
			my["max_jing"] += my["max_jing"];

		if (my["animaout"])
			my["max_jing"] += my["max_jing"];

		if (xflv > 180)
		{
			my["max_jing"] += (xflv-180)*2 + my["max_jing"]*((xflv-180)/5) / 100;
		}

		if(my["max_jing"]>10000000)
			my["max_jing"] = 10000000;
	}

	if (userp(ob) || undefinedp(my["max_qi"]))
	{
		s = ob->query_con() + ob->query_str();
		my["max_qi"] = 600;
		if (undefinedp(my["born"]))
			; else
		if (my["age"] < 14)
			my["max_qi"] = 260 + my["age"] * my["con"] / 2;
		else
		if (my["age"] < 28)
			my["max_qi"] += (my["age"] - 14) * s * 2 / 3;
		else
			my["max_qi"] += (27 - 14) * s * 2 / 3;

		if ((int)my["max_neili"] > 0)
			my["max_qi"] += (int)my["max_neili"] / 3;

		// �䵱̫������
		if ((x = (int)ob->query_skill("taoism", 1)) > 39 &&
		    (y = (int)ob->query_skill("taiji-shengong", 1)) > 39)
		{
			my["max_qi"] += (x-180)*5 + (x + 100 ) * (y + 100) / 50;
		}

		// ȫ�����칦����
		if ((x = (int)ob->query_skill("taoism", 1)) > 39 &&
		    (y = (int)ob->query_skill("xiantian-gong", 1)) > 39)
		{
			my["max_qi"] += (x + 85 ) * (y + 85) / 50;
		}

		// �����������������
		if ((x = (int)ob->query_skill("lamaism", 1)) > 39 &&
		    (y = (int)ob->query_skill("longxiang", 1)) > 39)
		{
			my["max_qi"] += (x + 65 ) * (y + 65) / 100;
		}

		if (my["breakup"])
			my["max_qi"] += my["max_qi"];
		if (my["con"]>28)
			my["max_qi"] += 300*(my["con"]-28);
		if(my["max_qi"]>1000000)
			my["max_qi"] = 10000000;

		if (ob->query("special_skill/ghost"))
			my["max_qi"] = my["max_qi"] * 7 / 10;

		if (xflv > 180)
		{
			my["max_qi"] += (xflv-180)*10 + my["max_qi"]*((xflv-180)/5) / 100;
		}
	}

	// ΪʲôҪ����0.7��������Ϊ����ֻ��Ҫ70%�ĸ��ء�
	if (! ob->query_weight())
		ob->set_weight((BASE_WEIGHT + (my["str"] - 10) * 2000) * 7 / 10);
	 level_old = ob->query_temp("mark/hubo");
	if ((level = ob->query_skill("zuoyou-hubo", 1)) > 0 && level_old != level)
	 {
		ob->set_temp("mark/hubo",level);
		ob->add_temp("apply/parry", -(level - level_old) / 4);
	 }
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
