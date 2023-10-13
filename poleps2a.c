ROM_START( poleps2a )
	/* Z80 memory/ROM data */
	ROM_REGION( 0x10000, REGION_CPU1, 0 )
	ROM_LOAD	 ( "180.7h",        0x0000, 0x2000, CRC(f85212c4) SHA1(666e55a7662247e72393b105b3e719be4233f1ff) )
	ROM_LOAD	 ( "183.7f",        0x2000, 0x1000, CRC(a9d4c380) SHA1(6048a8e858824936901e8e3e6b65d7505ccd82b4) )

	/* Z8002 #1 memory/ROM data */
	ROM_REGION( 0x10000, REGION_CPU2, 0 )
	ROM_LOAD16_BYTE( "176.3l",        0x0001, 0x2000, CRC(8aeaec98) SHA1(76b3bbb64a17090bf28858f1e91d2206a3beaf5b) )
	ROM_LOAD16_BYTE( "177.4l",        0x0000, 0x2000, CRC(7051df35) SHA1(cf23118ab05f5af273d756f97e6453496a276c9a) )

	/* Z8002 #2 memory/ROM data */
	ROM_REGION( 0x10000, REGION_CPU3, 0 )
	ROM_LOAD16_BYTE( "178.3e",        0x0001, 0x2000, CRC(eac35cfa) SHA1(f96005b3b63d85fc30695ab746af79c60f2f1341) )
	ROM_LOAD16_BYTE( "179.4e",        0x0000, 0x2000, CRC(613e917d) SHA1(97c139f8aa7bd871a907e72980757b83f99fd8a0) )
	ROM_LOAD16_BYTE( "184.3d",        0x4001, 0x2000, CRC(d893c4ed) SHA1(60d39abefbb0c8df68864a30b1f5fcbf4780c86c) )
	ROM_LOAD16_BYTE( "185.4d",        0x4000, 0x2000, CRC(899de75e) SHA1(4a16535115e37a3d342b2cb53f610a87c0d0abe1) )

	/* graphics data */
	ROM_REGION( 0x02000, REGION_GFX1, ROMREGION_DISPOSE ) 	/* 2bpp alpha layer */
	ROM_LOAD	 ( "172.7n",        0x0000, 0x2000, CRC(fbe5e72f) SHA1(07965d6e98ac1332ac6192b5e9cc927dd9eb706f) )

	ROM_REGION( 0x02000, REGION_GFX2, ROMREGION_DISPOSE ) 	/* 2bpp view layer */
	ROM_LOAD	 ( "173.6n",        0x0000, 0x2000, CRC(ec3ec6e6) SHA1(ae905d0ae802d1010b2c1f1a13e88a1f0dbe57da) )

	ROM_REGION( 0x04000, REGION_GFX3, ROMREGION_DISPOSE ) 	/* 4bpp 16x16 sprites */
	ROM_LOAD	 ( "170.13n",       0x0000, 0x2000, CRC(455d79a0) SHA1(03ef7c58f3145d9a6a461ef1aea3b5a49e653f80) )    /* 4bpp sm sprites, planes 0+1 */
	ROM_LOAD	 ( "171.12n",       0x2000, 0x2000, CRC(78372b81) SHA1(5defaf2074c1ab4d13dc36a190c658ddf7f7931b) )    /* 4bpp sm sprites, planes 2+3 */

	ROM_REGION( 0x10000, REGION_GFX4, ROMREGION_DISPOSE ) 	/* 4bpp 32x32 sprites */
	ROM_LOAD	 ( "119.13j",       0x0000, 0x2000, CRC(2e134b46) SHA1(0938f5f9f5cc6d7c1096c569449db78dbc42da01) )    /* 4bpp lg sprites, planes 0+1 */
	ROM_LOAD	 ( "166.13k",       0x2000, 0x2000, CRC(2b0517bd) SHA1(ebe447ba3dcd8a3b56f47d707483074f61953fec) )
	ROM_LOAD	 ( "168.13l",       0x4000, 0x2000, CRC(4d7916d9) SHA1(052745f252f51bfdd456e54cf7b8d22ab3aace27) )
	ROM_LOAD	 ( "175.13m",       0x6000, 0x2000, CRC(bd6df480) SHA1(58f39fa3ae43d94fe42dc51da341384a9c3879ae) )
	ROM_LOAD	 ( "120.12j",       0x8000, 0x2000, CRC(6f9997d2) SHA1(b26d505266ccf23bfd867f881756c3251c80f57b) )    /* 4bpp lg sprites, planes 2+3 */
	ROM_LOAD	 ( "167.12k",       0xa000, 0x2000, CRC(411e21b5) SHA1(9659ee429d819926b5e5b12c41b968ae6e7f186e) )
	ROM_LOAD	 ( "169.12l",       0xc000, 0x2000, CRC(662ff24b) SHA1(4cf8509034742c2bec8a96c7a786dafdf5875e4f) )
	ROM_LOAD	 ( "174.12m",       0xe000, 0x2000, CRC(f0c571dc) SHA1(9e6839e9e203fc120a0389f4e11c9d46a817dbdf) )

	/* graphics (P)ROM data */
	ROM_REGION( 0x7000, REGION_PROMS, 0 )
	ROM_LOAD	 ( "014-186.bpr",   0x0000, 0x0100, CRC(16d69c31) SHA1(f24b345448e4f4ef4e2f3b057b81d399cf427f88) )    /* red palette PROM */
	ROM_LOAD	 ( "014-187.bpr",   0x0100, 0x0100, CRC(07340311) SHA1(3820d1fa99013ed18de5d9400ad376cc446d1217) )    /* green palette PROM */
	ROM_LOAD	 ( "014-188.bpr",   0x0200, 0x0100, CRC(1efc84d7) SHA1(6946e1c209eec0a4b75778ae88111e6cb63c63fb) )    /* blue palette PROM */
	ROM_LOAD	 ( "014-189.bpr",   0x0300, 0x0100, CRC(064d51a0) SHA1(d5baa29930530a8930b44a374e285de849c2a6ce) )    /* alpha color PROM */
	ROM_LOAD	 ( "014-190.bpr",   0x0400, 0x0100, CRC(7880c5af) SHA1(e4388e354420be3f99594a10c091e3d2f745cc04) )    /* view color PROM */
	ROM_LOAD	 ( "014-142.bpr",   0x0500, 0x0100, CRC(2d502464) SHA1(682b7dd22e51d5db52c0804b7e27e47641dfa6bd) )    /* vertical position low PROM */
	ROM_LOAD	 ( "014-143.bpr",   0x0600, 0x0100, CRC(027aa62c) SHA1(c7030d8b64b80e107c446f6fbdd63f560c0a91c0) )    /* vertical position med PROM */
	ROM_LOAD	 ( "014-144.bpr",   0x0700, 0x0100, CRC(1f8d0df3) SHA1(b8f17758f114f5e247b65b3f2922ca2660757e66) )    /* vertical position hi PROM */
	ROM_LOAD	 ( "014-191.bpr",   0x0800, 0x0400, CRC(8b270902) SHA1(27b3ebc92d3a2a5c0432bde018a0e43669041d50) )    /* road color PROM */
	ROM_LOAD	 ( "014-192.bpr",   0x0c00, 0x0400, CRC(caddb0b0) SHA1(e41b89f2b40bf8f93546012f373ae63dcae870da) )    /* sprite color PROM */
	ROM_LOAD	 ( "131.11n",       0x1000, 0x1000, CRC(5921777f) SHA1(4d9c91a26e0d84fbbe08f748d6e0364311ed6f73) )    /* vertical scaling PROM */
	ROM_LOAD	 ( "127.2l",        0x2000, 0x2000, CRC(ee6b3315) SHA1(9cc26c6d3604c0f60d716f86e67e9d9c0487f87d) )    /* road control PROM */
	ROM_LOAD	 ( "128.2m",        0x4000, 0x2000, CRC(6d1e7042) SHA1(90113ff0c93ed86d95067290088705bb5e6608d1) )    /* road bits 1 PROM */
	ROM_LOAD	 ( "134.2n",        0x6000, 0x1000, CRC(4e97f101) SHA1(f377d053821c74aee93ebcd30a4d43e6156f3cfe) )    /* read bits 2 PROM */

	/* sound (P)ROM data */
	ROM_REGION( 0xd000, REGION_SOUND1, 0 )
	ROM_LOAD	 ( "014-118.bpr",   0x0000, 0x0100, CRC(8568decc) SHA1(0aac1fa082858d4d201e21511c609a989f9a1535) )    /* Namco sound PROM */
	ROM_LOAD	 ( "014-110.rom",   0x1000, 0x2000, CRC(b5ad4d5f) SHA1(c07e77a050200d6fe9952031f971ca35f4d15ff8) )    /* engine sound PROM */
	ROM_LOAD	 ( "014-111.rom",   0x3000, 0x2000, CRC(8fdd2f6f) SHA1(3818dc94c60cd78c4212ab7a4367cf3d98166ee6) )    /* engine sound PROM */
	ROM_LOAD	 ( "014-106.rom",   0x5000, 0x2000, CRC(5b4cf05e) SHA1(52342572940489175607bbf5b6cfd05ee9b0f004) )    /* voice PROM */

	/* unknown or unused (P)ROM data */
	ROM_REGION( 0x0100, REGION_USER1, 0 )
	ROM_LOAD	 ( "014-117.bpr",   0x0000, 0x0100, CRC(2401c817) SHA1(8991b7994513a469e64392fa8f233af5e5f06d54) )    /* sync chain */
ROM_END

