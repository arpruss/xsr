ROM_START( dspirit )
	ROM_REGION( 0x10000, REGION_CPU1, 0 )       /* 64k for the main cpu */
	/* Nothing loaded here. Bankswitching makes sure this gets the necessary code */

	ROM_REGION( 0x10000, REGION_CPU2, 0 )       /* 64k for the sub cpu */
	/* Nothing loaded here. Bankswitching makes sure this gets the necessary code */

	ROM_REGION( 0x2c000, REGION_CPU3, 0 )       /* 176k for the sound cpu */
	ROM_LOAD( "ds1_s0.bin",         0x0c000, 0x10000, CRC(27100065) SHA1(e8fbacaa43a5b858fce2ca3b579b90c1e016396b) )
	ROM_LOAD( "ds1_s1.bin",         0x1c000, 0x10000, CRC(b398645f) SHA1(e83208e2aea7b57b4a26f123a43c112e30495aca) )

	ROM_REGION( 0x100000, REGION_USER1, 0 ) /* 1M for ROMs */
	ROM_LOAD_HS( "ds3_p7.bin",      0x00000, 0x10000, CRC(820bedb2) SHA1(d05254c982635f9d184959065aacb10a077fcd34) )
	ROM_LOAD_HS( "ds3_p6.bin",      0x20000, 0x10000, CRC(fcc01bd1) SHA1(dd95388d2ccc5ab51b86da2242776dc82ac86901) )
	ROM_LOAD_HS( "ds1_p5.bin",      0x40000, 0x10000, CRC(9a3a1028) SHA1(505808834677c433e0a4cfbf387b2874e2d0fc47) )
	ROM_LOAD_HS( "ds1_p4.bin",      0x60000, 0x10000, CRC(f3307870) SHA1(a85d28c5dc55cbfa6c384d71e724db44c547d976) )
	ROM_LOAD_HS( "ds1_p3.bin",      0x80000, 0x10000, CRC(c6e5954b) SHA1(586fc108f264e91a4bbbb05153dd1aa19be81b5b) )
	ROM_LOAD_HS( "ds1_p2.bin",      0xa0000, 0x10000, CRC(3c9b0100) SHA1(1def48a28b68e1e36cd1a165eb7127b05982c54d) )
	ROM_LOAD_HS( "ds1_p1.bin",      0xc0000, 0x10000, CRC(f7e3298a) SHA1(76c924ed1311e7e292bd67f57c1e831054625bb6) )
	ROM_LOAD_HS( "ds1_p0.bin",      0xe0000, 0x10000, CRC(b22a2856) SHA1(8dea168e341460757c924bb510df4d4e9cdd908d) )

	ROM_REGION( 0x14000, REGION_USER2, 0 )  /* 80k for RAM */

	ROM_REGION( 0xb0000, REGION_CPU4, 0 )       /* the MCU & voice */
	ROM_LOAD( "ns1-mcu.bin",        0x0f000, 0x01000, CRC(ffb5c0bd) SHA1(7a38c0cc2553c627f4ec507fb6e807cf7d537c02) )
	ROM_LOAD_HS( "ds1_v0.bin",      0x10000, 0x10000, CRC(313b3508) SHA1(4770fb28b45abc4967534face0bf6794d30df71a) )
	ROM_LOAD( "ds_voi-1.bin",       0x30000, 0x20000, CRC(54790d4e) SHA1(d327b1c65c487dd691389920789c59f0eb1ecee1) )
	ROM_LOAD( "ds_voi-2.bin",       0x50000, 0x20000, CRC(05298534) SHA1(5ffd9018a5c1d5ce992dd3c7575b5e25945f14fa) )
	ROM_LOAD( "ds_voi-3.bin",       0x70000, 0x20000, CRC(13e84c7e) SHA1(6ad0eb50eb3312f614a891ae8d66faca6b48d204) )
	ROM_LOAD( "ds_voi-4.bin",       0x90000, 0x20000, CRC(34fbb8cd) SHA1(3f56f136e9d54d45924802f7149bfbc319e0933a) )

	ROM_REGION( 0x20000, REGION_GFX1, 0 )  /* character mask */
	ROM_LOAD( "ds_chr-8.bin",       0x00000, 0x20000, CRC(946eb242) SHA1(6964fff430fe306c575ff07e4c054c70aa7d96ca) )

	ROM_REGION( 0x100000, REGION_GFX2, ROMREGION_DISPOSE ) /* characters */
	ROM_LOAD( "ds_chr-0.bin",       0x00000, 0x20000, CRC(7bf28ac3) SHA1(af42b568be0c3919dbbc0e0c7a9d5ea39f84481a) )
	ROM_LOAD( "ds_chr-1.bin",       0x20000, 0x20000, CRC(03582fea) SHA1(c6705702bdb55ec6f993fc2582f116a8729c14d0) )
	ROM_LOAD( "ds_chr-2.bin",       0x40000, 0x20000, CRC(5e05f4f9) SHA1(ededa62c261ca75fc5e79c80840fc15b27cb3989) )
	ROM_LOAD( "ds_chr-3.bin",       0x60000, 0x20000, CRC(dc540791) SHA1(02c5c44bae878b22608cc6f9b09b0dd97c03e51a) )
	ROM_LOAD( "ds_chr-4.bin",       0x80000, 0x20000, CRC(ffd1f35c) SHA1(39f19676edc01059dfcee6b5c04527da3ef78ffa) )
	ROM_LOAD( "ds_chr-5.bin",       0xa0000, 0x20000, CRC(8472e0a3) SHA1(cece9fec70421fb09107890f108fb47ea770890d) )
	ROM_LOAD( "ds_chr-6.bin",       0xc0000, 0x20000, CRC(a799665a) SHA1(70cd630e63714b544f3f61a6663a41e3439639d5) )
	ROM_LOAD( "ds_chr-7.bin",       0xe0000, 0x20000, CRC(a51724af) SHA1(85728add3f773c4d814202208bee3d9a053e50de) )

	ROM_REGION( 0x100000, REGION_GFX3, ROMREGION_DISPOSE ) /* sprites */
	ROM_LOAD( "ds_obj-0.bin",       0x00000, 0x20000, CRC(03ec3076) SHA1(9926ec974ba3472d765531f6add4a8d6e398c46e) )
	ROM_LOAD( "ds_obj-1.bin",       0x20000, 0x20000, CRC(e67a8fa4) SHA1(c45070b929f3e4df0e3809cf33cb4538b0067464) )
	ROM_LOAD( "ds_obj-2.bin",       0x40000, 0x20000, CRC(061cd763) SHA1(df079052fddb60ea5618ed5a6c41fb4db0e313af) )
	ROM_LOAD( "ds_obj-3.bin",       0x60000, 0x20000, CRC(63225a09) SHA1(8fffcd5b6baaa9ced16fbac58f6a3eeb11183c8b) )
	ROM_LOAD_HS( "ds1_o4.bin",      0x80000, 0x10000, CRC(a6246fcb) SHA1(39de4fdb175ab16b791cdc5d757ff7bfee8e3d2b) )
ROM_END
