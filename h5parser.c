#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#pragma pack(1)
struct file_meta_block
{
	uint64_t signature;
	uint8_t ver_superblock;
	uint8_t ver_file_free_space_storage;
	uint8_t ver_root_grp_symtable_entry;
	uint8_t reserved1;
	uint8_t ver_shared_header_msg_format;
	uint8_t sizeof_offsets;
	uint8_t sizeof_lengths;
	uint8_t reserved2;
	uint16_t grp_leaf_node_K;
	uint16_t grp_int_node_K;
	uint32_t file_consistency_flags;
	//uint16_t indxd_storage_int_node_K;
	//uint16_t reserved3;
	uint64_t base_address;
	uint64_t file_free_space_info_address;
	uint64_t eof_address;
	uint64_t driver_info_block_address;
	uint32_t root_grp_symtable_entry;

};

void parse_file_meta_block(struct file_meta_block fb)
{
	printf("============== [VERSION 0 SUPERBLK] ==================\n");
	printf("SIGNATURE:                     0x%016llx \n"
			"VER SUPERBLK:                  0x%x \n"
			"VER FILE FREE SPACE STORAGE:   0x%x \n"
			"ROOT GRP SYMTABLE ENTRY:       0x%x \n"
			"RESERVED \n"
			"VER SHARED HEADER MSG FORMAT:  0x%x \n"
			"SIZE OFFSETS:                  0x%x \n"
			"SIZE LENGTHS:                  0x%x \n"
			"RESERVED \n"
			"GRP LEAF NODE K:               0x%x \n"
			"GRP INTERNAL NODE K:           0x%x \n"
			"FILE CONSISTENCY FLAGS:        0x%x \n"
			//"INDEXED STORAGE INTERNAL NODE: 0x%x \n"
			//"RESERVED \n"
			"BASE ADDRESS:                  0x%016llx \n"
			"FILE FREE SPACE INFO:          0x%016llx \n"
			"EOF ADDRESS:                   0x%016llx \n"
			"DRIVER INFO BLOCK ADDRESS:     0x%016llx \n"
			"ROOT GRP SYMTABLE ENTRY:       0x%x \n",
			fb.signature, fb.ver_superblock, fb.ver_file_free_space_storage,
			fb.ver_root_grp_symtable_entry, fb.ver_shared_header_msg_format,
			fb.sizeof_offsets, fb.sizeof_lengths,
			fb.grp_leaf_node_K, fb.grp_int_node_K, fb.file_consistency_flags,
			//fb.indxd_storage_int_node_K, 
			fb.base_address, fb.file_free_space_info_address,
			fb.eof_address, fb.driver_info_block_address, fb.root_grp_symtable_entry);
}

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		printf("Filename needs to be specified\n");
		return -1;
	}
	FILE *fp;
	if((fp = fopen(argv[1], "r")) == NULL) return -1;
	struct file_meta_block header;
	fread(&header, sizeof(struct file_meta_block), 1, fp);
	parse_file_meta_block(header);
	fclose(fp);
	return 0;
}
