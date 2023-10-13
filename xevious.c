ROM_START( xevious )
	ROM_REGION( 0x10000, REGION_CPU1, 0 )	/* 64k for the first CPU */
	ROM_LOAD( "xvi_1.3p",     0x0000, 0x1000, CRC(09964dda) SHA1(4882b25b0938a903f3a367455ba788a30759b5b0) )
	ROM_LOAD( "xvi_2.3m",     0x1000, 0x1000, CRC(60ecce84) SHA1(8adc60a5fcbca74092518dbc570ffff0f04c5b17) )
	ROM_LOAD( "xvi_3.2m",     0x2000, 0x1000, CRC(79754b7d) SHA1(c6a154858716e1f073b476824b183de20e06d093) )
	ROM_LOAD( "xvi_4.2l",     0x3000, 0x1000, CRC(c7d4bbf0) SHA1(4b846de204d08651253d3a141677c8a31626af07) )

	ROM_REGION( 0x10000, REGION_CPU2, 0 )	/* 64k for the second CPU */
	ROM_LOAD( "xvi_5.3f",     0x0000, 0x1000, CRC(c85b703f) SHA1(15f1c005b9d806a384ab1f2240b9c580bfe83893) )
	ROM_LOAD( "xvi_6.3j",     0x1000, 0x1000, CRC(e18cdaad) SHA1(6b79efee1a9642edb9f752101737132401248aed) )

	ROM_REGION( 0x10000, REGION_CPU3, 0 )	/* 64k for the audio CPU */
	ROM_LOAD( "xvi_7.2c",     0x0000, 0x1000, CRC(dd35cf1c) SHA1(f8d1f8e019d8198308443c2e7e815d0d04b23d14) )

	ROM_REGION( 0x1000, REGION_GFX1, ROMREGION_DISPOSE )
	ROM_LOAD( "xvi_12.3b",    0x0000, 0x1000, CRC(088c8b26) SHA1(9c3b61dfca2f84673a78f7f66e363777a8f47a59) )	/* foreground characters */

	ROM_REGION( 0x2000, REGION_GFX2, ROMREGION_DISPOSE )
	ROM_LOAD( "xvi_13.3c",    0x0000, 0x1000, CRC(de60ba25) SHA1(32bc09be5ff8b52ee3a26e0ac3ebc2d4107badb7) )	/* bg pattern B0 */
	ROM_LOAD( "xvi_14.3d",    0x1000, 0x1000, CRC(535cdbbc) SHA1(fb9ffe5fc43e0213231267e98d605d43c15f61e8) )	/* bg pattern B1 */

	ROM_REGION( 0x8000, REGION_GFX3, ROMREGION_DISPOSE )
	ROM_LOAD( "xvi_15.4m",    0x0000, 0x2000, CRC(dc2c0ecb) SHA1(19ddbd9805f77f38c9a9a1bb30dba6c720b8609f) )	/* sprite set #1, planes 0/1 */
	ROM_LOAD( "xvi_18.4r",    0x2000, 0x2000, CRC(02417d19) SHA1(b5f830dd2cf25cf154308d2e640f0ecdcda5d8cd) )	/* sprite set #1, plane 2, set #2, plane 0 */
	ROM_LOAD( "xvi_17.4p",    0x4000, 0x2000, CRC(dfb587ce) SHA1(acff2bf5cde85a16cdc98a52cdea11f77fadf25a) )	/* sprite set #2, planes 1/2 */
	ROM_LOAD( "xvi_16.4n",    0x6000, 0x1000, CRC(605ca889) SHA1(3bf380ef76c03822a042ecc73b5edd4543c268ce) )	/* sprite set #3, planes 0/1 */
	/* 0xa000-0xafff empty space to decode sprite set #3 as 3 bits per pixel */

	ROM_REGION( 0x4000, REGION_GFX4, 0 )	/* background tilemaps */
	ROM_LOAD( "xvi_9.2a",     0x0000, 0x1000, CRC(57ed9879) SHA1(3106d1aacff06cf78371bd19967141072b32b7d7) )
	ROM_LOAD( "xvi_10.2b",    0x1000, 0x2000, CRC(ae3ba9e5) SHA1(49064b25667ffcd81137cd5e800df4b78b182a46) )
	ROM_LOAD( "xvi_11.2c",    0x3000, 0x1000, CRC(31e244dd) SHA1(3f7eac12863697a98e1122111801606759e44b2a) )

	ROM_REGION( 0x0b00, REGION_PROMS, 0 )
	ROM_LOAD( "xvi_8bpr.6a",  0x0000, 0x0100, CRC(5cc2727f) SHA1(0dc1e63a47a4cb0ba75f6f1e0c15e408bb0ee2a1) ) /* palette red component */
	ROM_LOAD( "xvi_9bpr.6d",  0x0100, 0x0100, CRC(5c8796cc) SHA1(63015e3c0874afc6b1ca032f1ffb8f90562c77c8) ) /* palette green component */
	ROM_LOAD( "xvi10bpr.6e",  0x0200, 0x0100, CRC(3cb60975) SHA1(c94d5a5dd4d8a08d6d39c051a4a722581b903f45) ) /* palette blue component */
	ROM_LOAD( "xvi_7bpr.4h",  0x0300, 0x0200, CRC(22d98032) SHA1(ec6626828c79350417d08b98e9631ad35edd4a41) ) /* bg tiles lookup table low bits */
	ROM_LOAD( "xvi_6bpr.4f",  0x0500, 0x0200, CRC(3a7599f0) SHA1(a4bdf58c190ca16fc7b976c97f41087a61fdb8b8) ) /* bg tiles lookup table high bits */
	ROM_LOAD( "xvi_4bpr.3l",  0x0700, 0x0200, CRC(fd8b9d91) SHA1(87ddf0b9d723aabb422d6d416aa9ec6bc246bf34) ) /* sprite lookup table low bits */
	ROM_LOAD( "xvi_5bpr.3m",  0x0900, 0x0200, CRC(bf906d82) SHA1(776168a73d3b9f0ce05610acc8a623deae0a572b) ) /* sprite lookup table high bits */

	ROM_REGION( 0x0200, REGION_SOUND1, 0 )	/* sound PROMs */
	ROM_LOAD( "xvi_2bpr.7n",  0x0000, 0x0100, CRC(550f06bc) SHA1(816a0fafa0b084ac11ae1af70a5186539376fc2a) )
	ROM_LOAD( "xvi_1bpr.5n",  0x0100, 0x0100, CRC(77245b66) SHA1(0c4d0bee858b97632411c440bea6948a74759746) )	/* timing - not used */
ROM_END
