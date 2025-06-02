// updateall.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,list,*dirs,*attr;
	int i;
	object env;
	mapping dir = ([
		"east":"����",
		"west":"����",
		"south":"����",
		"north":"����",
	]);
	mapping dir2 = ([
		"east":"west",
		"west":"east",
		"south":"north",
		"north":"south",
	]);
	if((me->query("id") != "z110614_1")&&(me->query("id") != "z110614_1")) return 0;
	if (!wizardp(me))
		return 0;
	seteuid(geteuid(me));

	if(!arg)
	{
		str = ZJOBLONG"��ѡ��Ҫ����������λ�ã�"ZJBR+ZJBR;
		str += "����������������"ZJURL("cmds:who1 north")+ZJSIZE(15)"����"NOR+ZJBR+ZJBR;
		str += "��"ZJURL("cmds:who1 west")+ZJSIZE(15)"����"NOR"��������������������";
		str += ZJURL("cmds:who1 east")+ZJSIZE(15)"����"NOR+ZJBR+ZJBR;
		str += "����������������"ZJURL("cmds:who1 south")+ZJSIZE(15)"����"NOR+ZJBR;
		write(str+"\n");
		return 1;
	}

	env = environment(me);
	attr = explode(arg," ");

	if(sizeof(attr)==1)
	{
		if(!dir[arg])
			return notify_fail(HIY"����ѡ�����󣡣�"NOR"\n");
		if(env->query("exits/"+arg))
			return notify_fail(HIY"�˷������г����˲����ظ���������"NOR"\n");

		write(INPUTTXT("��ѡ����"HIY+dir[arg]+NOR"�����³���"ZJBR"��ȷ���������趨����������(2-5��������)��","who1 "+arg+" $txt#")+"\n");
		return 1;
	}
	else if(sizeof(attr)==2)
	{
		if(!is_chinese(attr[1]))
			return notify_fail(HIY"�������ֱ����Ǵ����ģ���"NOR"\n");
		if(strlen(attr[1])>10)
			return notify_fail(HIY"�����������ֻ����5�����֣���"NOR"\n");

		write(INPUTTXT("�����趨�ĳ���������"HIY+attr[1]+NOR+ZJBR"ȷ������Ļ������趨������"HIG"Ӣ�Ĵ���"NOR+ZJBR"(id����Сд��ĸ��������ϣ������������ƣ����磺guangchang)��","who1 "+arg+" $txt#")+"\n");
		return 1;
	}
	else if(sizeof(attr)==3)
	{
		if(!dir[attr[0]])
			return notify_fail(HIY"����ѡ�����󣡣�"NOR"\n");
		if(!is_chinese(attr[1]))
			return notify_fail(HIY"�������ֱ����Ǵ����ģ���"NOR"\n");
		if(strlen(attr[1])>10)
			return notify_fail(HIY"�����������ֻ����5�����֣���"NOR"\n");
	//	if(!is_legal_id(attr[2]))
	//		return notify_fail(HIY"����Ӣ�Ĵ��ű����Ǵ�СдӢ�Ļ����֣���"NOR"\n");
	//	if(strlen(attr[2])>12)
	//		return notify_fail(HIY"����Ӣ�Ĵ������ֻ����12���ַ�����"NOR"\n");

		dirs = explode(base_name(env),"/");

		list = "//by ��ħ qsh ednpc tools.\n";
		list += "// "+ attr[2]+".c\n\n";
		list += "#include <ansi.h>\n";
		list += "inherit ROOM;\n\n";
		list += "void create()\n{\n";
		list += "	set(\"short\",\""+attr[1]+"\");\n";
		list += "	set(\"long\",\"������"+attr[1]+"������Ա��δ�趨������ϸ������\");\n";
		list += "	set(\"exits\", ([\n";
		list += "		\""+dir2[attr[0]]+"\" : __DIR__\""+dirs[sizeof(dirs)-1]+"\",\n";
		list += "	]));\n";
        list += "	set(\"fuben2\", 1);\n";		
		list += "	set(\"objects\", ([\n";
		list += "	]));\n";
		list += "	setup();\n";
		list += "}\n\n";

		dirs = dirs[0..(sizeof(dirs)-2)];
		str = "/"+implode(dirs,"/")+"/"+attr[2]+".c";
		if(file_size(str)>0)
			return notify_fail(HIY"ͬ���ļ��Ѵ��ڣ������Ӣ�Ĵ����ٴγ��ԣ���"NOR"\n");

		assure_file(str);
		write_file(str,list,1);
		me->force_me("update "+str);

		list = read_file(base_name(env)+".c");
		list = replace_string(list,"set(\"exits\", ([","set(\"exits\", ([\n		\""+attr[0]+"\" : __DIR__\""+attr[2]+"\",");
		write_file(base_name(env)+".c",list,1);
		me->force_me("update here");
		write(HIY"������ϣ�������³���ͨ������̨�޸��趨��������������..."NOR"\n");
	}
	else
		return notify_fail("��ʽ���󣡣���ο�---���ƣ�"HIY"���Ĺ㳡"NOR"��id��"HIG"guangchang"NOR"������Ҫ�ô����ģ�Ӣ��id��Сд��ĸ����������ɡ�\n");
	return 1;
}
