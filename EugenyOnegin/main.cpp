#include <iostream>
#include <algorithm>


struct StringPointer {
		char * pointer_  = nullptr;
		int length_ = 0;
};

class Text {
	FILE * book_;
	char * text_buffer_;
	StringPointer * string_pointer_buffer_;
	int size_string_buffer_;
	long int size_text_;
public:
		Text(const char* file_name) {

			if ((book_ = fopen(file_name, "r")) == NULL) {
				printf("cannot open the file - %s\n", file_name);
			}
			fseek(book_, 0, SEEK_END);
			size_text_ = ftell(book_);
			fseek(book_, 0, SEEK_SET);

			text_buffer_ = (char *)calloc(size_text_ + 1, sizeof(char)); //char может не хватить
			fread(text_buffer_, (size_text_) * sizeof(char), 1, book_);

			size_string_buffer_ = GetStringCount();
			GetStringPointerBuffer();

			fclose(book_);
		}

		~Text() {
			free(string_pointer_buffer_);
			free(text_buffer_);
		}

		void SortStringsLess(const char * file_name){
			std::sort(string_pointer_buffer_, string_pointer_buffer_ + size_string_buffer_, CompareLess);

			WriteStringPointers(string_pointer_buffer_, file_name);
		}

		void SortStringGreater(const char * file_name) {
			std::sort(string_pointer_buffer_, string_pointer_buffer_ + size_string_buffer_, CompareGreater);

			WriteStringPointers(string_pointer_buffer_, file_name);
		}

private:
		int GetStringCount() {
			int len = 0;
			bool is_empty = true;

			for (int i = 0; i < size_text_; i++) {//empty strings ain't considered

				if (text_buffer_[i] != '\n' && text_buffer_[i] != '\r' && is_empty) {
					is_empty = false;
				}
				if ((text_buffer_[i] == '\n' || text_buffer_[i] == '\r') && !is_empty) {
					len++;
					is_empty = true;
				}

			}
			return len;
		}

		void GetStringPointerBuffer() {
			string_pointer_buffer_ = (StringPointer *)calloc(size_string_buffer_, sizeof(StringPointer));

			bool is_newline = true;
			int item = 0;

			if (text_buffer_[0] != '\n' && text_buffer_[0] != '\r') {
				string_pointer_buffer_[0].pointer_ = text_buffer_;
				item++;
				is_newline = false;
			}

			for (int i = 1; i < size_text_; i++) {
				if (text_buffer_[i] != '\n' && text_buffer_[i] != '\r' && is_newline) {
					string_pointer_buffer_[item++].pointer_ = text_buffer_ + i;
					is_newline = false;
				}
				if ((text_buffer_[i] == '\n' || text_buffer_[i] == '\r' || text_buffer_[i] == '\0')
																																						&& !is_newline) {
					string_pointer_buffer_[item-1].length_ = text_buffer_ + i - string_pointer_buffer_[item-1].pointer_;
					is_newline = true;
				}
			}
		}

		void WriteStringPointers(StringPointer * string_pointer, const char* file_name) {
			FILE * book = NULL;
			if ((book = fopen(file_name, "w")) == NULL) {
				printf("cannot open the file - %s\n", file_name);
			}

			for (int i = 0; i < size_string_buffer_; i++) {
				fwrite(string_pointer[i].pointer_, sizeof(char), string_pointer[i].length_, book);
				fputc('\n', book);
			}

			fclose(book);
		}

		static bool CompareLess(StringPointer str_pointer1, StringPointer str_pointer2) {

			int size1 = str_pointer1.length_;
			int size2 = str_pointer2.length_;

			char * pointer1 = str_pointer1.pointer_;
			char * pointer2 = str_pointer2.pointer_;

			int i;
			for (i = 0; (pointer1[i] == pointer2[i]) && i < std::min(size1, size2); i++);

			if (i == std::min(size1, size2)) {
				return false;
			}
			return pointer1[i] < pointer2[i];

		}

		static bool CompareGreater(StringPointer str_pointer1, StringPointer str_pointer2) {

			int size1 = str_pointer1.length_;
			int size2 = str_pointer2.length_;


			char * pointer1 = str_pointer1.pointer_;
			char * pointer2 = str_pointer2.pointer_;

			int i = size1, j = size2;

			while (i >= 0 || j >= 0) {
				i--;
				j--;
				while(if_punctum(pointer1[i])) {
					i--;
				}
				while(if_punctum(pointer2[j])) {
					j--;
				}
				if (i >= 0 && j >= 0 && pointer1[i] != pointer2[j]) {
					break;
				}
			}

			if (j == -1 || i == -1) {
				return false;
			}
			return pointer1[i] < pointer2[j];
		}

		static bool if_punctum(char c) {
			return (c == ' ' || c == ',' || c == '.' || c == ';'
							|| c == ':' || c == '\"' || c == '\'' || c == '\t'
							|| c =='?' || c == '!' || c == '-');
		}
};



int main() {

	Text text("../EugeneOnegin");
	text.SortStringsLess("../SortedOnegin");
	text.SortStringGreater("../ReversedSortedOnegin");

	return 0;
}