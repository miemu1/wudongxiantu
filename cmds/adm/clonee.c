// clone.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object env,obj;
	string dir,str,err, msg;
	string *tmp,file,*files;
	int amount,i,j;

	if (! SECURITY_D->valid_grant(me, "(wizard)"))
		return 0;
if (/*! SECURITY_D->valid_grant(me, "(admin)") ||*/ !wizardp(me))
		return 0;
	seteuid(getuid());

	seteuid(getuid());
	env = environment(me);
	tmp = explode(base_name(env),"/");
	tmp -= ({tmp[sizeof(tmp)-1]});
	dir = "/"+implode(tmp,"/")+"/";

	if (! arg )
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ������\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		str += "�������:clonee objh"ZJSEP"��Ҫ���:clonee objs"ZJSEP"clone/0:clonee sword"ZJSEP"clone/zi:clonee zi"ZJSEP
			"clone/good:clonee unarmed"ZJSEP"����NPC:clonee npch"ZJSEP"����NPC:clonee npcs"ZJSEP"clone/aaa:clonee aaa"ZJSEP"clone/vip:clonee vip"ZJSEP"clone/gift:clonee gift"ZJSEP"clone/vip2:clonee vip2"ZJSEP"clone/tianji1:clonee tianji1"ZJSEP"clone/shizhe:clonee shizhe";
		write(str+"\n");
		return 1;
	}
	else if (arg=="objh")
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ���Ʒ��\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs(dir+"obj/");
		if(!sizeof(files))
			return notify_fail("����û�п��ñ�׼�����\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = dir+"obj/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}
	else if (arg=="objs")
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ���Ʒ��\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/baowu/");
		if(!sizeof(files))
			return notify_fail("���ļ���ʱû����Ʒ��\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/baowu/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}
	else if (arg=="npch")
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ�NPC��\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs(dir+"npc/");
		if(!sizeof(files))
			return notify_fail("����û�п��ñ�׼NPC��\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = dir+"npc/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}
	else if (arg=="sword")
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ�clone/0����ļ���\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/0/");
		if(!sizeof(files))
			return notify_fail("��ʱû��clone/0������ļ���\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/0/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}
	else if (arg=="unarmed")
	{
		str = ZJOBLONG"��ѡ����Ҫ����good����ļ���\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/good/");
		if(!sizeof(files))
			return notify_fail("��ʱû��good�ļ���Ʒ��\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/good/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}
	else if (arg=="aaa")
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ��ļ���\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/aaa/");
		if(!sizeof(files))
			return notify_fail("��ʱû��aaa�ļ���Ʒ��\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/aaa/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}
	
	else if (arg=="shizhe")
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ��ļ���\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/shizhe/");
		if(!sizeof(files))
			return notify_fail("��ʱû��shizhe�ļ���Ʒ��\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/shizhe/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}	
	
	else if (arg=="vip2")
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ��ļ���\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/vip2/");
		if(!sizeof(files))
			return notify_fail("��ʱû��vip2�ļ���Ʒ��\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/vip2/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}	
	else if (arg=="zi")
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ��ļ���\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/zi/");
		if(!sizeof(files))
			return notify_fail("��ʱû��vip2�ļ���Ʒ��\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/zi/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}	
	
	else if (arg=="tianji1")
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ��ļ���\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/tianji1/");
		if(!sizeof(files))
			return notify_fail("��ʱû��vip2�ļ���Ʒ��\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/tianji1/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}	
	else if (arg=="vip")
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ��ļ���\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/vip/");
		if(!sizeof(files))
			return notify_fail("��ʱû��vip�ļ���Ʒ��\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/vip/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}	
	else if (arg=="zi")
	{
		if(me->query("id") != "z110614_1")
		{return 0;}
	else{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ��ļ���\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/zi/");
		if(!sizeof(files))
			return notify_fail("��ʱû��zi�ļ���Ʒ��\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/zi/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}
	}	
	else if (arg=="gift")
	{
		str = ZJOBLONG"��ѡ����Ҫ���Ƶ��ļ���\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/gift/");
		if(!sizeof(files))
			return notify_fail("��ʱû��gift�ļ���Ʒ��\n");
		for(i=0;i<sizeof(files);i++)
		{
			file = "/clone/gift/"+files[i];
			if (file[strlen(file) - 1] != 'c' || file[strlen(file) - 2] != '.'||!file->query("name"))
				continue;
			str += file->query("name")+":clonee "+file+ZJSEP;
		}
		write(str+"\n");
		return 1;
	}	
	
	if (sscanf(arg, "%s %d", file, amount) != 2)
	{
		if(file_size(arg)<0 && file_size(arg+".c")<0)
			return notify_fail("��Ʒѡ����󣡣�\n");

		if(arg->query_amount())
		{
			write(INPUTTXT("��"+arg->query("name")+"��Ϊ�ɵ�����Ʒ��������������","clonee "+arg+" $txt#")+"\n");
			return 1;
		}
		file = arg;
		amount = 1;
	}

	if (amount < 1)
		amount = 1;

	file = resolve_path(me->query("cwd"), file);
	if (sscanf(file, "%*s.c") != 1) file += ".c";
	me->set("cwf", file);

	if (file_size(file) < 0)
		return notify_fail("û���������(" + file + ")��\n");

	// ����Ը��ļ��ɶ����ܸ��ơ�
	/*
	if (! SECURITY_D->valid_read(file, me, "clone"))
	{
		write("��û��Ȩ�޲����������\n");
		return 1;
	}
*/
	if (! find_object(file))
	{
		err = catch(call_other(file, "???"));
		if (err)
		{
			write("����ʧ�ܣ�" + err + "\n");
			return 1;
		}
	}

	seteuid(geteuid(me));

	err = catch(obj = new(file));
	if (err)
	{
		write("����ʧ�ܣ�" + err + "\n");
		return 1;
	}

	if (! objectp(obj))
	{
		write("���޷����Ƹ���Ʒ��\n");
		return 1;
	}

	msg = "ֻ��$N�������һָ�������$n��\n";

	obj->set_amount(amount);
	log_file("static/clonee", sprintf("%s %-9s clonee %s(%d)\n",
					 log_time(), geteuid(me),
					 base_name(obj), amount));
	if (! obj->is_character() && obj->move(me))
	{
		write(obj->name(1) + "���Ƴɹ������������Ʒ����\n");
		message_vision(msg + "\n", me, obj);
	} else
	if (obj->move(environment(me)))
	{
		write(obj->name(1) + "���Ƴɹ�������������䡣\n");
		message_vision(msg + "\n", me, obj);
	} else
	{
		destruct(obj);
		return notify_fail("�޷����Ʋ����ƶ������(" + file + ")��\n");
	}

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : clone <�ļ���> [<����>]

���ô�ָ��ɸ����κ����ƶ�֮���(������)��

�������ڿ��Ա���Ȩʹ�õ���Ϣ������gift��all��

see also : dest
HELP );
	return 1;
}
