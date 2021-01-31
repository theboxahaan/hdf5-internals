#include<cstdint>
#include<cstdlib>
#include<iostream>

using namespace std;

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
	uint16_t indxd_storage_int_node_K;
	uint16_t reserved3;
	uint32_t base_address;
	uint32_t file_free_space_info_address;
	uint32_t eof_address;
	uint32_t driver_info_block_address;
	uint32_t root_grp_symtable_entry;

	friend std::ostream& operator <<(std::ostream& os, struct file_meta_block const& a)
	{ return 
		os << "SIGNATURE: 0x" << std::hex << (uint64_t)a.signature << "\n"
		   << "VER_SUPERBLK: 0x" << (uint8_t)a.ver_superblock << "\n"
		   << "VER FILE FREE SPACE STORAGE: 0x" << (uint8_t)a.ver_file_free_space_storage << "\n"
		   << "VER SHRD HEADER MSG FORMAT: 0x" << a.ver_shared_header_msg_format << "\n"
		   << "SIZEOF OFFSETS: 0x" << a.sizeof_offsets << "\n"
		   << "SIZEOF LENGTHS: 0x" << a.sizeof_lengths << "\n"
		   << "GRP LEAF NODE K: 0x" << a.grp_leaf_node_K << "\n"
		   << "GRP INT NODE K: 0x" <<  a.grp_int_node_K << "\n"
		   << "FILE CONSIST. FLAGS: 0x" << a.file_consistency_flags << "\n"
		   << "INDEXED STORAEGE INT NODES: 0x" <<  a.indxd_storage_int_node_K << "\n"
		   << "BASE ADDRESS: 0x" << a.base_address << "\n"
		   << "FILE FREE SPACE INFO ADD: 0x" << a.file_free_space_info_address << "\n"
		   << "EOF ADDRESS: 0x" << a.eof_address << "\n"
		   << "DRIVER INFO BLK ADD: 0x" << a.driver_info_block_address << "\n"
		   << "ROOT GRP SYMTABLE ENTRY: 0x" << a.root_grp_symtable_entry << "\n"
		   ;
		    
	}		   
	
};



void parse_file_meta_block()
{
	return ;
}

int main(int argc, char** argv)
{
	cout << " the hdf5 parser" << endl;
	if(argc < 2)
	{
		cout << "filename needs to be passed" << endl;
		return 0;
	}
	/* for some weird reason there is no way to read *void vals in cpp
	
	std::ifstream fd(argv[1], std::ifstream::binary);
	struct file_meta_block header;
	fd.get((char *)&header, sizeof(struct file_meta_block));
	*/
	FILE *fd;
	if((fd = fopen(argv[1], "r")) == NULL)return -1;
	struct file_meta_block header;
	fread(&header, sizeof(struct file_meta_block), 1, fd);
	cout << header << endl;
	fclose(fd);
	return 0;
}

