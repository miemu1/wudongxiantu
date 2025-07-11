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
		str = ZJOBLONG"请选择你要复制的物件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		str += "本区物件:clonee objh"ZJSEP"重要物件:clonee objs"ZJSEP"clone/0:clonee sword"ZJSEP"clone/zi:clonee zi"ZJSEP
			"clone/good:clonee unarmed"ZJSEP"本区NPC:clonee npch"ZJSEP"公共NPC:clonee npcs"ZJSEP"clone/aaa:clonee aaa"ZJSEP"clone/vip:clonee vip"ZJSEP"clone/gift:clonee gift"ZJSEP"clone/vip2:clonee vip2"ZJSEP"clone/tianji1:clonee tianji1"ZJSEP"clone/shizhe:clonee shizhe";
		write(str+"\n");
		return 1;
	}
	else if (arg=="objh")
	{
		str = ZJOBLONG"请选择你要复制的物品：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs(dir+"obj/");
		if(!sizeof(files))
			return notify_fail("本区没有可用标准物件。\n");
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
		str = ZJOBLONG"请选择你要复制的物品：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/baowu/");
		if(!sizeof(files))
			return notify_fail("该文件暂时没有物品。\n");
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
		str = ZJOBLONG"请选择你要复制的NPC：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs(dir+"npc/");
		if(!sizeof(files))
			return notify_fail("本区没有可用标准NPC。\n");
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
		str = ZJOBLONG"请选择你要复制的clone/0里的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/0/");
		if(!sizeof(files))
			return notify_fail("暂时没有clone/0里面的文件。\n");
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
		str = ZJOBLONG"请选择你要复制good里的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/good/");
		if(!sizeof(files))
			return notify_fail("暂时没有good文件物品。\n");
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
		str = ZJOBLONG"请选择你要复制的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/aaa/");
		if(!sizeof(files))
			return notify_fail("暂时没有aaa文件物品。\n");
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
		str = ZJOBLONG"请选择你要复制的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/shizhe/");
		if(!sizeof(files))
			return notify_fail("暂时没有shizhe文件物品。\n");
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
		str = ZJOBLONG"请选择你要复制的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/vip2/");
		if(!sizeof(files))
			return notify_fail("暂时没有vip2文件物品。\n");
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
		str = ZJOBLONG"请选择你要复制的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/zi/");
		if(!sizeof(files))
			return notify_fail("暂时没有vip2文件物品。\n");
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
		str = ZJOBLONG"请选择你要复制的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/tianji1/");
		if(!sizeof(files))
			return notify_fail("暂时没有vip2文件物品。\n");
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
		str = ZJOBLONG"请选择你要复制的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/vip/");
		if(!sizeof(files))
			return notify_fail("暂时没有vip文件物品。\n");
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
		str = ZJOBLONG"请选择你要复制的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/zi/");
		if(!sizeof(files))
			return notify_fail("暂时没有zi文件物品。\n");
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
		str = ZJOBLONG"请选择你要复制的文件：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
		files = list_dirs("/clone/gift/");
		if(!sizeof(files))
			return notify_fail("暂时没有gift文件物品。\n");
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
			return notify_fail("物品选择错误！！\n");

		if(arg->query_amount())
		{
			write(INPUTTXT("【"+arg->query("name")+"】为可叠加物品，请输入数量：","clonee "+arg+" $txt#")+"\n");
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
		return notify_fail("没有这个档案(" + file + ")。\n");

	// 必须对该文件可读才能复制。
	/*
	if (! SECURITY_D->valid_read(file, me, "clone"))
	{
		write("你没有权限操作这个对象。\n");
		return 1;
	}
*/
	if (! find_object(file))
	{
		err = catch(call_other(file, "???"));
		if (err)
		{
			write("载入失败：" + err + "\n");
			return 1;
		}
	}

	seteuid(geteuid(me));

	err = catch(obj = new(file));
	if (err)
	{
		write("复制失败：" + err + "\n");
		return 1;
	}

	if (! objectp(obj))
	{
		write("你无法复制该物品。\n");
		return 1;
	}

	msg = "只见$N伸手凌空一指，变出了$n。\n";

	obj->set_amount(amount);
	log_file("static/clonee", sprintf("%s %-9s clonee %s(%d)\n",
					 log_time(), geteuid(me),
					 base_name(obj), amount));
	if (! obj->is_character() && obj->move(me))
	{
		write(obj->name(1) + "复制成功，放在你的物品栏。\n");
		message_vision(msg + "\n", me, obj);
	} else
	if (obj->move(environment(me)))
	{
		write(obj->name(1) + "复制成功，放在这个房间。\n");
		message_vision(msg + "\n", me, obj);
	} else
	{
		destruct(obj);
		return notify_fail("无法复制不能移动的物件(" + file + ")。\n");
	}

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : clone <文件名> [<数量>]

利用此指令可复制任何能移动之物件(含人物)。

该命令在可以被授权使用的信息包括：gift、all。

see also : dest
HELP );
	return 1;
}
